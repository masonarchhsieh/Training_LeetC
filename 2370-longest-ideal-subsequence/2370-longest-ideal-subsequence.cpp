class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0;
        for (auto &c : s) {
            for (auto i = c - k; i <= c + k; i++)
                dp[c] = max(dp[c], dp[i]);
            res = max(res, ++dp[c]);
        }

        return res;
    }
};