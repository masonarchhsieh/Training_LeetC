// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add_num = 1;
        int itr = digits.size() - 1;

        while (itr >= 0 && add_num > 0) {
            if (digits[itr] + add_num >= 10) {
                digits[itr] = (digits[itr] + add_num) % 10;
                if (itr == 0)
                    digits.insert(digits.begin(), add_num);
            }
            else
            {
                digits[itr] += add_num;
                add_num = 0;
            }
            itr--;
        }
        return digits;
    }
};