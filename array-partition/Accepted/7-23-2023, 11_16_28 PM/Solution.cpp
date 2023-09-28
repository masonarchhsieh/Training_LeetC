// https://leetcode.com/problems/array-partition

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size()== 1)
            return nums[0];
        int res = 0;
        for (auto i = 0; i < nums.size(); i+=2) {
            res += nums[i];
        }

        return res;
    }
};