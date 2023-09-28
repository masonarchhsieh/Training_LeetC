// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter

class Solution {
public:
    int minTimeToType(string word) {
        int cnt = 1;
        if (word[0] != 'a')
            cnt += min(word[0] - 'a', (26 - (word[0] - 'a')));
        for (size_t i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
            } else {
                cnt += getMinTwoChars(word[i], word[i - 1]);
                cnt += 1;
            }
        }

        return cnt;
    }

    int getMinTwoChars(char a, char b) {
        if (a >= b)
            return min(a - b, 26 - (a - b));
        // b > a
        return min(b - a, 26 - (b - a));
    }
};