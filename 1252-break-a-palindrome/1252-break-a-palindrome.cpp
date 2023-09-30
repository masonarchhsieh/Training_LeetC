class Solution {
public:
    string breakPalindrome(string palindrome) {
        unordered_set<string> res;
        for (auto i = 'a'; i <= 'z'; i++) {
            for (auto pos = 0; pos < palindrome.length(); pos++) {
                string s = palindrome;
                s[pos] = i;
                if (s == palindrome)
                    continue;
                if (!isPalindrome(s)) {
                    res.insert(s);
                }
            }
        }

        if (res.empty())
            return "";
        string s = *(res.begin());
        for (auto i : res) {
            if (i < s)
                s = i;
        }
        return s;
    }

    bool isPalindrome(string s) {
        for (size_t i = 0; i < s.length() / 2; i++)
            if (s[i] != s[s.length() - 1 - i])
                return false;
        return true;
    }
};