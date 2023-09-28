// https://leetcode.com/problems/sum-multiples

class Solution {
public:
    int sumOfMultiples(int n) {
        int res = 0;
        for (auto i = 1; i <= n; ++i) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
                res += i;
        }

        return res;
    }
};