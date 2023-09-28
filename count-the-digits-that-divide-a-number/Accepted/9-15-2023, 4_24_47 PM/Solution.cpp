// https://leetcode.com/problems/count-the-digits-that-divide-a-number

class Solution {
public:
    int countDigits(int num) {
        int _num = num;
        int cnt = 0;
        while (_num > 0) {
            cnt += (num % (_num % 10) == 0);
            _num /= 10;
        }
        return cnt;
    }
};