// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res;
        int idx_i = 0, idx_d = s.length(), i = 0;
        while (i < s.length()) {
            if (s[i] == 'I')
                res.push_back(idx_i++);
            else if (s[i] == 'D')
                res.push_back(idx_d--);
            i++;
        }
        res.push_back(idx_i);

        return res;
    }
};