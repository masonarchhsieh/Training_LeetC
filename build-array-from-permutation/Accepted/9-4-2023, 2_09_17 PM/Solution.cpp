// https://leetcode.com/problems/build-array-from-permutation

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res;
        int i = 0;

        while (i < nums.size()) {
            res.push_back(nums[nums[i++]]);
        }
        return res;
    }
};