// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        int itr = 0;
        int res = 0;
        
        while (itr < s)
        {
            for (int i=itr + 1; i<s; i++)
            {
                if (prices[i] - prices[itr]  > res)
                    res = prices[i] - prices[itr];
            }
            
            itr++;
        }
        
        
        return res;        
    }
};