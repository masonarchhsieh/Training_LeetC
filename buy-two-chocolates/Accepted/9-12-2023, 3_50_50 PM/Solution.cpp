// https://leetcode.com/problems/buy-two-chocolates

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        for (auto i = 1; i < prices.size(); i++) {
            prices[i - 1] = prices[i - 1] + prices[i];
        }
        prices.pop_back();
        if (money < prices[0])
            return money;
        int res = money - prices[0];
        for (auto i : prices) {
            if (money - i >= 0)
                res = max(res, money - i);
        }


        return res;
    }
};