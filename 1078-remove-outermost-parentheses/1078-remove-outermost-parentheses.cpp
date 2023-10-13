class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int opened = 0;
        for (char c : s) {
            if (c == '(' && opened++ > 0)
                res.push_back(c);
            if (c == ')' && opened-- > 1)
                res.push_back(c);
        }

        return res;
    }
};