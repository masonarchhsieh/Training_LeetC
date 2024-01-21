class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return helper(n - 1, nums, dp);
    }
    
    int helper(int idx, vector<int> &nums, vector<int> &dp) {
        if (idx == 0)
            return dp[0] = nums[0];
        if (idx == 1)
            return dp[1] = max(nums[0], nums[1]);
        if (dp[idx] != -1)
            return dp[idx];
        
        int robThisHouse = nums[idx] + helper(idx - 2, nums, dp);
        int skipThisHouse = helper(idx - 1, nums, dp);
        
        return dp[idx] = max(robThisHouse, skipThisHouse);
    }
};