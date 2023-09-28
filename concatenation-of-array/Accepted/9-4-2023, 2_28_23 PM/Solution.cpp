// https://leetcode.com/problems/concatenation-of-array

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        res.assign(nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());

        return res;
    }
};