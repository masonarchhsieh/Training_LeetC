// https://leetcode.com/problems/convert-a-number-to-hexadecimal

class Solution {
    unordered_map<int, string> hex_list = {
        {0, "0"},
        {1, "1"},
        {2, "2"},
        {3, "3"},
        {4, "4"},
        {5, "5"},
        {6, "6"},
        {7, "7"},
        {8, "8"},
        {9, "9"},
        {10, "a"},
        {11, "b"},
        {12, "c"},
        {13, "d"},
        {14, "e"},
        {15, "f"},
    };
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        return helper(num);
    }

    string helper(int num) {
        string res = "";

        if (num > 0) {
            res = helper(num / 16) + hex_list[num % 16];
        }
        if (num < 0) {
            res = helper(abs(INT_MIN - num));
            if (res.length() != 0)
                res[0] = 'f';
            else
                res = "80000000";
        }
        return res;
    }
};