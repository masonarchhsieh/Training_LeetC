// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case

class Solution {
public:
    string greatestLetter(string s) {
        string res = "";
        for (size_t i = 0; i < s.length(); i++) {
            if (isupper(s[i]) && s.find(tolower(s[i])) != std::string::npos) {
                string tmp;
                tmp.push_back(s[i]);
                res = max(res, tmp);
            }
        }

        return res;
    }
};