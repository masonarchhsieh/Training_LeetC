// https://leetcode.com/problems/maximum-number-of-words-you-can-type

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> letters;
        for (size_t i = 0; i < brokenLetters.length(); i++) {
            letters.insert(brokenLetters[i]);
        }

        stringstream ss(text);
        int cnt = 0;
        while (ss) {
            string tmp;
            ss >> tmp;
            bool count = (tmp.length() > 0);
            for (auto i = 0; i < tmp.length(); i++) {
                if (letters.find(tmp[i]) != letters.end()) {
                    count = false;
                    break;
                }
            }
            if (count)
                cnt++;
        }
        return cnt;
    }
};