// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = 0;
        vector<int> nums_new(nums.size(), nums[0]);
        for (auto i = 1; i < nums.size(); i++) {
            nums_new[i] = max(nums_new[i - 1] + 1, nums[i]);
        }

        for (auto i = 0; i < nums.size(); i++)
            n += (nums_new[i] - nums[i]);

        return n;
    }
};