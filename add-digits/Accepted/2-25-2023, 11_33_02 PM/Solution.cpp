// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        
        if (num < 10)
            return num;

        while (num > 0) {
            res += (num % 10);
            num /= 10;
        }

        return addDigits(res);
    }
};