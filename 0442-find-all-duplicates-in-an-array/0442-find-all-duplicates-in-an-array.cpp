class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto i : nums)
            m[i]++;

        for (auto i : m)
            if (i.second > 1)
                res.push_back(i.first);
        return res;
    }
};