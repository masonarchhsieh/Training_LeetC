class Solution {
public:
    // greedy alg
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < (int) size(prices); i++) {
            int day_profit = prices.at(i) - prices.at(i - 1);
            profit += (day_profit > 0)? day_profit : 0; 
        }
        return profit;
    }
};