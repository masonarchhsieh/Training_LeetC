class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;

        for (int i = 0; i < size(prices); i++) {
            buy = max(buy, sell - prices.at(i));
            sell = max(sell, buy + prices.at(i) - fee);
        }
        return sell;
    }
};