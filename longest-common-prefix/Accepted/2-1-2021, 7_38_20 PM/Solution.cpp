// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        if (strs.size() == 0)
            return "";
        
        int min_len = strs[0].length();
        for (int i=1; i<strs.size(); i++)
            min_len = (strs[i].length() < min_len)? strs[i].length() : min_len;
        
        string res;
        for (int i=0; i<min_len; i++) {
            for (int j=1; j<strs.size(); j++)
                if (strs[j-1][i] != strs[j][i])
                    goto end;

            res += strs[0][i];
        }
        
        end:
        return res;
    }
};