class Solution {

public:
    int longestBeautifulSubstring(string word) {
        int res = 0;
        int cnt = 1, len = 1;
        for (auto i = 1; i < size(word); i++) {
            if (word[i - 1] <= word[i]) {
                cnt += (word[i - 1] != word[i]);
                len++;

                if (cnt == 5)
                    res = max(res, len);
                continue;
            }
            cnt = 1, len = 1;
        }

        return res;
    }
};