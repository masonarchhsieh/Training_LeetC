class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length() - 1;
        
        while (isspace(s[i]) && i >= 0)
            i--;
        
        while (i >= 0 && isalpha(s[i])) {
            len++;
            i--;
        }
        return len;
    }
};