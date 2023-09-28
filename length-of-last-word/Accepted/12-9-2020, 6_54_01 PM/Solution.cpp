// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int itr = s.length() - 1;
        int res = 0;
        while (isspace(s[itr])) {
            itr--;
        }
        
        while(isalpha(s[itr])) {
            res++;
            itr--;
        }
        
        
        return res;
    }
};