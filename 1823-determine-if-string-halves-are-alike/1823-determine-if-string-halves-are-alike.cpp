class Solution {
    const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
public:
    bool halvesAreAlike(string s) {
        std::multiset<char> s_1, s_2;
        int half_len = size(s) / 2;

        for (size_t i = 0; i < half_len; i++) {
            if (find(vowels, vowels + 5, tolower(s.at(i))) != end(vowels))
                s_1.insert(tolower(s.at(i)));
            if (find(vowels, vowels + 5, tolower(s.at(i + half_len))) != end(vowels))
                s_2.insert(tolower(s.at(i + half_len)));
        }

        return size(s_1) == size(s_2);
    }
};