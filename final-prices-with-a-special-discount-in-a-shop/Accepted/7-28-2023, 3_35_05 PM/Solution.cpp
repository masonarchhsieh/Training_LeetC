// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        int tmp;
        for (auto i = 0; i < prices.size(); i++) {
            tmp = prices[i];
            for (auto j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    tmp = prices[i] - prices[j];
                    break;
                }
            }
            res.push_back(tmp);
        }

        return res;
    }
};