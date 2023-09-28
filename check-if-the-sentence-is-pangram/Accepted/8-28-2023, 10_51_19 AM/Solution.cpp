// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for (size_t i = 0; i < sentence.length(); i++) {
            if (!islower(sentence[i]))
                return false;
            s.insert(sentence[i]);
        }

        return s.size() == 26;
    }
};