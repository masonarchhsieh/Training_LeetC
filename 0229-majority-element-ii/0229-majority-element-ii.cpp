class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int req = nums.size() / 3;
        vector<int> v;
        unordered_map<int, int> m;
        for (auto i : nums)
            m[i]++;
        for (auto i : m)
            if (i.second > req)
                v.push_back(i.first);
        return v;
    }
};