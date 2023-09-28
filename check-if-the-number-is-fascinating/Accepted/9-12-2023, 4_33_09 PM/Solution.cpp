// https://leetcode.com/problems/check-if-the-number-is-fascinating

class Solution {
public:
    bool isFascinating(int n) {
        vector<bool> digits(10, false);
        if (n > 333)
            return false;
        string s = to_string(n) + to_string(n * 2) + to_string(n * 3);
        for (auto i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                return false;
            digits[s[i] - '0'] = true;
        }

        return count(digits.begin() + 1, digits.end(), true) == 9;
    }
};