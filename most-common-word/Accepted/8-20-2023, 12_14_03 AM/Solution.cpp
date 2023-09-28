// https://leetcode.com/problems/most-common-word

class Solution {
public:
    void removeSpecialCharacters(string &s)
    {
        int j = 0;
        for (auto i = 0; i < s.length(); ++i) {
            if (s[i] == ',') {
                s[j] = ' ';
                j++;
            }
            else if (isalpha(s[i])) {
                s[j] = tolower(s[i]);
                j++;
            }
            else if (isspace(s[i])) {
                s[j] = s[i];
                j++;
            }
        }
        s = s.substr(0, j);
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        removeSpecialCharacters(paragraph);
        map<string, int> words;
        stringstream ss;
        ss << paragraph;
        while (ss) {
            string tmp;
            ss >> tmp;
            words[tmp]++;
        }

        int max_cnt = -1;
        string res = "";
        for (auto i : words) {
            if (find(banned.begin(), banned.end(), i.first) == banned.end()) {
                if (i.second >= max_cnt) {
                    max_cnt = i.second;
                    res = i.first;
                }
            }
        }

        return res;
    }
};