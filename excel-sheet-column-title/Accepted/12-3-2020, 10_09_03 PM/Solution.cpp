// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n > 0) {
            if (n%26 == 0)
                res = 'Z' + res;
            else
                res = char (n % 26 - 1 + 'A' ) + res;
            n--;
            n /= 26;
        }
        
        
        return res;
    }
};