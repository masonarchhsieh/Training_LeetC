class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int cntL = 0, cntR = 0;

        for (auto i = 0; i < size(s); i++) {
            if (s[i] == 'R')
                cntR++;
            if (s[i] == 'L')
                cntL++;
            if (cntR == cntL && cntR != 0) {
                cntR = 0;
                cntL = 0;
                res++;
            }
        }

        return res;
    }
};