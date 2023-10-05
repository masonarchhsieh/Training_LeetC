class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        unordered_set<int> unique_set;
        unordered_map<int, int> m;
        // get unique set
        for (auto i : nums)
            unique_set.insert(i);
        // start counting
        for (auto r = 0, l = 0; r < nums.size(); r++) {
            m[nums[r]]++;
            if (m.size() == unique_set.size())
                res += (nums.size() - r);
            while (m.size() == unique_set.size()) {
                m[nums[l]]--;
                if (m[nums[l++]] == 0)
                    m.erase(nums[l-1]);
                if (m.size() == unique_set.size())
                    res += (nums.size() - r);
            }
        }
        return res;
    }
};