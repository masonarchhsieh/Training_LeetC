// https://leetcode.com/problems/maximum-69-number

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        
        while (num > 0) {
            digits.push_back(num % 10);
            num = num / 10;
        }
        
        for (int i=digits.size()-1; i>=0; i--)
            if (digits[i] == 6) {
                digits[i] = 9;
                break;
            }
        
        reverse(digits.begin(), digits.end());
        int res = 0;
        for (int i=0; i<digits.size(); i++)
            res = res * 10 + digits[i];
        
        return res;
        
    }
};