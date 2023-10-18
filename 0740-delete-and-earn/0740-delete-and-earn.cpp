class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int _max = *max_element(begin(nums), end(nums));
        
        int dp[_max + 1], n = size(nums);
        std::memset(dp, 0, sizeof(int) * (_max + 1));
        for (auto i : nums)
            dp[i] += i;
        for (auto i = 2; i < _max + 1; i++) {
            dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
        }

        return dp[_max];
    }
};