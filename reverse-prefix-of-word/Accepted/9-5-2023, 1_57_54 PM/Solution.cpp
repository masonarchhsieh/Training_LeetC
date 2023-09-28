// https://leetcode.com/problems/reverse-prefix-of-word

class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t found = word.find(ch);
        if (found == std::string::npos)
            return word;
        for (size_t i = 0; i < (found + 1) / 2; i++) {
            swap(word[i], word[found - i]);
        }
        return word;
    }
};