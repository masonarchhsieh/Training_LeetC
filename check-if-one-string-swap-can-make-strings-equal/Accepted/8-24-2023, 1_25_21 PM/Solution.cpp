// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        for (size_t i = 0; i < s1.length(); i++) {
            for (size_t j = i + 1; j < s1.length(); j++) {
                swap(s1[i], s1[j]);
                if (s1 == s2)
                    return true;
                swap(s1[i], s1[j]);
            }
        }

        return false;
    }
};