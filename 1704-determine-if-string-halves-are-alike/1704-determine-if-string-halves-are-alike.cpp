class Solution {
    const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
public:
    bool halvesAreAlike(string s) {
        int vows1 = 0, vows2 = 0;
        int half_len = size(s) / 2;

        for (size_t i = 0; i < half_len; i++) {
            if (find(vowels, vowels + 5, tolower(s.at(i))) != end(vowels))
                vows1++;
            if (find(vowels, vowels + 5, tolower(s.at(i + half_len))) != end(vowels))
                vows2++;
        }

        return vows1 == vows2;
    }
};