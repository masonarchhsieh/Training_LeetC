// https://leetcode.com/problems/count-prefixes-of-a-given-string

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;

        for (auto i : words) {
            bool prefix = true;
            for (auto j = 0; j < i.length() && j < s.length(); j++) {
                if (i[j] != s[j]) {
                    prefix = false; 
                    break;
                }
            }
            if (i.length() <= s.length())
                cnt += (prefix);
        }

        return cnt;
    }
};