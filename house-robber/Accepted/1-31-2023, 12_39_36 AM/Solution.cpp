// https://leetcode.com/problems/house-robber

class Solution {
public:
    int getMaxAmount(int indx, vector<int> &nums, vector<int> &dp) {
        // base cases, 
        // if indx == 0, then can rob this house 
        if(indx == 0) return dp[0] = nums[0];
        // if indx == 1, then can rob either this or 0th house whichever has maximum amount
        if(indx == 1) return dp[1] = max(nums[0], nums[1]);

        if(dp[indx] != -1) return dp[indx];

        int robThisHouse = nums[indx] + getMaxAmount(indx - 2, nums, dp);
        int leaveThisHouse = getMaxAmount(indx - 1, nums, dp);

        return dp[indx] = max(robThisHouse, leaveThisHouse);
    }
    int rob(vector<int>& nums) {
        // using memoization (dp)
        int n = nums.size();
        vector<int> dp (nums.size() + 1, -1);
        return getMaxAmount(n -1, nums, dp);
    }
};