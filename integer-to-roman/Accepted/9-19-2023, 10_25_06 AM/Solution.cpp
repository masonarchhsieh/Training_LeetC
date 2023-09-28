// https://leetcode.com/problems/integer-to-roman

class Solution {
    vector<pair<int, string>> symbols = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };
public:
    string intToRoman(int num) {
        string res = "";

        for (auto i = 0; i < symbols.size(); i++) {
            while (symbols[i].first <= num) {
                res += symbols[i].second;
                num -= symbols[i].first;
            }
        }

        return res;
    }
};