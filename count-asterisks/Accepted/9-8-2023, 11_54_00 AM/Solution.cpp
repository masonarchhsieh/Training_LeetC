// https://leetcode.com/problems/count-asterisks

class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        bool inPair = false;
        
        for (auto i = 0; i < s.length(); i++) {
            if (s[i] == '|') {
                inPair = !inPair;
            }
            else if (s[i] == '*' && !inPair) {
                cnt++;
            }
        }


        return cnt;
    }
};