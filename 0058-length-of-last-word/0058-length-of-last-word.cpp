class Solution {
public:
    int lengthOfLastWord(string s) {
        int prevLen = 0, curLen = 0;

        for (auto i = 0; i < s.length(); i++) {
            if (isspace(s[i])) {
                curLen = 0;
                continue;
            }
            curLen++;
            prevLen = (curLen == 0)? prevLen : curLen;
        }

        return prevLen;
    }
};