// https://leetcode.com/problems/largest-3-same-digit-number-in-string

class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for (auto i = 0; i < num.length() - 2; i++) {
            if (num[i] != num[i+1] || num[i] != num[i+2])
                continue;

            if (res.length() == 0)
                res = num.substr(i, 3);
            else
                res = (stoi(res) >= stoi(num.substr(i, 3)))? res : num.substr(i, 3);
        }

        return res;
    }
};