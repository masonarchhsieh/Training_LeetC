// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        string res(len1 + len2, '0');
        
        for (auto i = len1 - 1; i >= 0; i--) {
            for (auto j = len2 - 1; j >= 0; j--) {
                int diff = (num1[i] - '0') * (num2[j] - '0') + (res[i+j+1] - '0');
                res[i + j + 1] = diff % 10 + '0';
                res[i + j] += diff / 10;
            }
        }

        for (auto i = 0; i < res.length(); i++) {
            if (res[i] != '0')
                return res.substr(i);
        }

        return "0";
    }
};