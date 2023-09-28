// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (auto i = 1; i <= n / 2; i++) {
            if (n % i == 0)
                cnt++;
            if (cnt > 3)
                return false;
        }
        cnt++;
        return (cnt == 3);
    }
};