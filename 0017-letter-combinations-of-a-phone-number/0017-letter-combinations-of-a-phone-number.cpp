class Solution {
    vector<vector<string>> buttons = {
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"},
    };

    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() < 1)
            return res;
        backtrack("", digits);
        return res;
    }

    void backtrack(string combination, string digits) {
        if (digits == "") {
            res.push_back(combination);
            return;
        }
        int pos = digits.back() - '2';
        digits.pop_back();
        if (pos < 0 || pos > 8)
            backtrack(combination, digits);
        for (auto i = 0; i < buttons[pos].size(); i++) {
            backtrack( buttons[pos][i] + combination, digits);
        }
    }
};