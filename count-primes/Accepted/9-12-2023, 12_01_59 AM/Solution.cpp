// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n, true);
        if (v.size() < 3)
            return 0;
        v[0] = v[1] = false;
        int count = 1;
        for (auto i = 3; i < n; i+= 2) {
            if (v[i]) {
                count++;
                for (auto j = i * 3; j < n; j += 2 * i)
                    v[j] = false;
            }
        }
        return count;
    }
};