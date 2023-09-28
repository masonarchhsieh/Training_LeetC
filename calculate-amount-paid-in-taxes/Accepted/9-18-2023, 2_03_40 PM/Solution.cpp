// https://leetcode.com/problems/calculate-amount-paid-in-taxes

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if (income == 0)
            return 0.0;
        int prev = 0;
        double res = 0.0;
        for (auto i = 0; i < brackets.size(); i++) {
            int act = min(brackets[i][0], income);
            res += ((act - prev) * brackets[i].back()) / 100.00;
            if (brackets[i][0] > income)
                break;
            prev = brackets[i][0];
        }
        return res;
    }
};