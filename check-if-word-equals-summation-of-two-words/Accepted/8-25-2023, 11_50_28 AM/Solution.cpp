// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return (covertStringToNum(firstWord) + covertStringToNum(secondWord) == covertStringToNum(targetWord));
    }

    int covertStringToNum(string s) {
        int n = 0;
        for (size_t i = 0; i < s.length(); i++) {
            n = (n) * 10 + (s[i] - 'a');
        }
        return n;
    }
};