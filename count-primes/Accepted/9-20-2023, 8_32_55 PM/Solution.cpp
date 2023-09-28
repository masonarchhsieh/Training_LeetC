// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> isPrime(n + 1, true);
        int cnt = 1;
        isPrime[0] = false;
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                cnt++;
                for (int j = i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return cnt;
    }
};