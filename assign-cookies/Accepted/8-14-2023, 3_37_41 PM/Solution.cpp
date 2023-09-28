// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int m = g.size(), n = s.size(), itr_g = 0, itr_s =0;
        while (itr_g < m && itr_s < n) {
            if (g[itr_g] > s[itr_s]) {
                itr_s++;
                continue;
            }
            cnt++;
            itr_g++;
            itr_s++;
        }
        return cnt;
    }
};