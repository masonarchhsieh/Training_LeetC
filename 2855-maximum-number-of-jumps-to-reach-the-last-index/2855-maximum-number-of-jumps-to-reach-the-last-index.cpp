class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(size(nums), -1);
        dp[0] = 0;
        for (int i = 0; i < size(nums); i++) {
            if (dp[i] == -1)
                continue;
            for (int j = i + 1; j < size(nums); j++) {
                if (target < abs(nums.at(j) - nums.at(i)))
                    continue;
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }

        return dp.back();
    }
};