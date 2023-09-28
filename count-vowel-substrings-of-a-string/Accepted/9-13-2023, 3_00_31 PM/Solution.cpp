// https://leetcode.com/problems/count-vowel-substrings-of-a-string

class Solution {
public:
    int countVowelSubstrings(string word) {
        char vows[5] = { 'a', 'e', 'i', 'o', 'u' };
        // unordered_set<string> res;
        int res = 0;
        size_t left = 0, right = 0;

        while (left < word.length()) {
            bool allvows[5] = { false };
            for (right = left; right < word.size(); right++) {
                char *c = std::find(std::begin(vows), std::end(vows), word[right]);
                if (c != std::end(vows)) {
                    allvows[c - std::begin(vows)] = true;
                    if (std::find(std::begin(allvows), std::end(allvows), false) == std::end(allvows)) {
                        res++;
                        // res.insert(word.substr(left, right - left + 1));
                    }
                } else {
                    break;
                }
            }
            left++;
        }

        return res;
    }
};