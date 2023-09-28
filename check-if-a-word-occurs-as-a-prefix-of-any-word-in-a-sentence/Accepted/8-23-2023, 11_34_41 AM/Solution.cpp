// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n_word = 0;
        stringstream ss(sentence);
        string tmp;
        while (ss) {
            ss >> tmp;
            n_word++;
            if (tmp.find(searchWord) == 0)
                return n_word;
        }

        return -1;
    }
};