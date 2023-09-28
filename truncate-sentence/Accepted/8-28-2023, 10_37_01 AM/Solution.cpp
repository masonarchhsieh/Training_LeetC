// https://leetcode.com/problems/truncate-sentence

class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        stringstream ss(s);
        while (k-- > 0 && ss) {
            string tmp;
            ss >> tmp;
            tmp += " ";
            res += tmp;
        }
        return res.substr(0, res.length() - 1);
    }
};