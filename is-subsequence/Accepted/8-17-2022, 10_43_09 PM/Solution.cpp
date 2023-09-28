// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0)
            return true;
        if (t.length() == 0)
            return false;
        
        bool res = false;
        int itr_s = 0;
        
        for (int i=0; i<t.length(); i++) {
            if (t[i] == s[itr_s]) {
                itr_s++;
                if (itr_s == s.length())
                {
                    res = true;
                    goto end;
                }
            }
        }
        
end:
        return res;
    }
};