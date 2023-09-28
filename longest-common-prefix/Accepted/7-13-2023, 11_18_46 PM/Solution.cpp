// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;

        for (auto i = 0; i < strs[0].length(); i++)
        {
            for (auto j = 1; j < strs.size(); j++) 
                if (strs[0][i] != strs[j][i])
                    return prefix;
            prefix += strs[0][i];  
        }

        return prefix;
    }
};