// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> primes(n + 1, true);
        if (n < 3)
            return 0;
        primes[0] = primes[1] = false;

        for (auto i = 2; i < n; i++) {
            if (primes[i]) {
                cnt++;
                for (auto j = i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return cnt;
    }
};