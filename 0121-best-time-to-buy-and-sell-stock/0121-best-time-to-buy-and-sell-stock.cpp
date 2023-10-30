class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector <int> dp(prices.size(), 0);
        
        for (int i=1; i<prices.size(); i++)
        {
            dp[i] = max(dp[i], dp[i - 1] + prices[i] - prices[i - 1]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};