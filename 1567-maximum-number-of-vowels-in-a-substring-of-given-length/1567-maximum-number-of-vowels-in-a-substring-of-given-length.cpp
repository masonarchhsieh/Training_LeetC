class Solution {
public:
    int maxVowels(string s, int k) {
        // k is the window length
        int res = 0, vowels_in_the_window = 0;
        size_t i = 0;

        for (i = 0; i < size(s); i++) {
            if (isVowel(s[i]))
                vowels_in_the_window++;
            if (i >= k && isVowel(s[i - k]))
                vowels_in_the_window--;
            
            res = max(res, vowels_in_the_window);
        }

        return res;
    }

    bool isVowel(const char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};