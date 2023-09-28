// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add_num = 1;
        int pos = digits.size() - 1;
        while (pos >= 0 && add_num > 0) {
            if (digits[pos] + add_num >= 10) {
                digits[pos] = (digits[pos] + add_num) % 10;
                if (pos == 0)
                    digits.insert(digits.begin(), add_num);
            } else {
                digits[pos] += add_num;
                add_num = 0;
            }
            pos--;
        }
        return digits;
    }
};