class Solution {
public:
    int minOperations(string s) {
        return min(helper(s, true), helper(s, false));
    }

    int helper(string& s, bool startWithZero) {
        int ops = 0;
        for (size_t i = 0; i < s.length(); i++) {
            if (startWithZero) {
                if (i % 2 == 0 && s[i] != '0')
                    ops++;
                else if (i % 2 == 1 && s[i] != '1')
                    ops++;
            }
            else {
                if (i % 2 == 0 && s[i] != '1')
                    ops++;
                else if (i % 2 == 1 && s[i] != '0')
                    ops++;
            }
        }

        return ops;
    }
};