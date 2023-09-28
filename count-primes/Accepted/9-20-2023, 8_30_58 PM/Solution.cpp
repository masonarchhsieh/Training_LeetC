// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        int cnt = 0;
        
        if (n < 2)
            return 0;
        isPrime[0] = false;
        isPrime[1] = true;
        for (int i = 2; i < n; i++) {
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