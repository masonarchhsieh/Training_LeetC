// https://leetcode.com/problems/sum-of-digits-in-base-k

class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0, n_ten = 0;
        while (n > 0) {
            res += (n % k) * pow(10, n_ten++);
            n /= k;
        }
        int sum = 0;
        while (res > 0) {
            sum += (res % 10);
            res /= 10;
        }
        return sum;
    }
};