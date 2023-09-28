// https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        const char vows[5] = { 'a', 'e', 'i', 'o', 'u' };
        int cnt = 0;

        for (auto i = left; i <= right; i++) {
            if (find(vows, vows + 5, words[i].front()) != vows + 5 && 
                find(vows, vows + 5, words[i].back()) != vows + 5) { cnt++; }
        }

        return cnt;
    }
};