// https://leetcode.com/problems/odd-string-difference

class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].length();
        int m = words.size();
        for (auto i = 1; i < n; i++) {
            for (auto j = 1; j < m; j++) {
                if (words[j-1][i] - words[j-1][i-1] != words[j][i] - words[j][i-1]) {
                    if (j-1 == 0) {
                        if (words[j-1][i] - words[j-1][i-1] != words[j+1][i] - words[j+1][i-1])
                            return words[0];
                    }
                    return words[j];
                }
            }
        }

        return "";
    }
};