class Solution {
public:
    int countVowelStrings(int n) {
        string vowels = "aeiou";
        // return helper(n, 0, vowels);
        return count(n);
    }

    int helper(int n, int idx, string &vowels) {
        if (n == 0)
            return 1;
        if (idx >= 5)
            return 0;
        int pick, npick;
        pick = helper(n - 1, idx, vowels);
        npick = helper(n, idx + 1, vowels);
        
        return pick + npick;
    }

    int count(int n) {
        const string vowels = "aeiou";
        vector<vector<int>> dp(size(vowels), vector<int>(n + 1, 0));

        for (auto i = 0; i < size(vowels); i++)
            dp[i][0] = 1;
        
        for (auto i = 4; i >= 0; i--) {
            for (auto j = 1; j <= n; j++) {
                int pick = 0, npick = 0;
                pick = dp[i][j - 1];
                if (i < 4)
                    npick = dp[i + 1][j];
                dp[i][j] = pick + npick;
            }
        }
        return dp[0][n];
    }
};