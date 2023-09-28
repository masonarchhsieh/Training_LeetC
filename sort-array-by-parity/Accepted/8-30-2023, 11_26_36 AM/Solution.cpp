// https://leetcode.com/problems/sort-array-by-parity


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> t;
        for (auto i : nums)
            if (i % 2 == 0)
                t.push_back(i);
        for (auto i : nums)
            if (i % 2 == 1)
                t.push_back(i);
        return t;
    }
};