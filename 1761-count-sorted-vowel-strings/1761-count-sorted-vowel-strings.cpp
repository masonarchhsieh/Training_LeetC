class Solution {
public:
    int countVowelStrings(int n) {
        string vowels = "aeiou";
        return helper(n, 0, vowels);
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
};