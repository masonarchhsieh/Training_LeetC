// https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value

class Solution {
public:
    bool digitCount(string num) {
        for (int i = 0; i < num.length(); i++) {
            if (count(num.begin(), num.end(), '0' + i) != num[i] - '0') {
                return false;
            }
            if (num[i] - '0' >= num.length())
                return false;
        }


        return true;
    }
};