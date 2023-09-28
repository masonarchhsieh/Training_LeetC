// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0;
        for (auto i = 1; i <= n; i++) {
            if (n / i == 0)
                break;
            n -= i;
            l++;
        }

        return l;
    }
};