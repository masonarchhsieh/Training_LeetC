class Solution {
    static bool isVowel(const char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    long long countVowels(string word) {
        long long res = 0;

        for (size_t i = 0; i < size(word); i++) {
            if (isVowel(word[i]))
                res += (long) (size(word) - i) * (long) (i + 1);

        }

        return res;
    }
};