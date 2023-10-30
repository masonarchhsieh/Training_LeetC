constexpr bool isPalindrome(const string &s) {
    int l = 0, r = size(s) - 1;
    while (l < r) {
        if (s[l++] != s[r--])              
            return false;
    }
    return true;
}

class Solution {
public:
    int maxProduct(string s) {
        int n = size(s);
        int res = 0;
        string s1 = "", s2 = "";
        backtrack(0, s1, s2, s, res);
        return res;
    }

    void backtrack(int i, string &s1, string &s2, string &s, int &res) {
        if (i >= size(s)) {
            if ((isPalindrome(s1) && isPalindrome(s2))) {
                res = max(res, (int) (size(s1) * size(s2)));
            }
            return;
        }

        backtrack(i + 1, s1, s2, s, res);
        s1.push_back(s[i]);
        backtrack(i + 1, s1, s2, s, res);
        s1.pop_back();
        s2.push_back(s[i]);
        backtrack(i + 1, s1, s2, s, res);
        s2.pop_back();
    }
};