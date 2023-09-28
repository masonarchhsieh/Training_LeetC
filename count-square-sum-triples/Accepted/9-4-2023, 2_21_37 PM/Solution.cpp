// https://leetcode.com/problems/count-square-sum-triples

class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

        for (auto i = 1; i < n; i++) {
            for (auto j = 1; j < n; j++) {
                if (isTriples(i * i + j * j, n))
                    cnt++;
            }
        }

        return cnt;
    }
    bool isTriples(int match, int n) {
        for (auto i = 1; i * i <= match && i <= n; i++) {
            if (i * i == match)
                return true;
        }

        return false;
    }
};