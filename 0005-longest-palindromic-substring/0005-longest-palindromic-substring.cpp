class Solution {
public:
    string dp(string s, int l, int r) {
        while (l >= 0 && r < size(s) && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    
    string longestPalindrome(string s) {
        string res = "";
        for (auto i = 0; i < size(s); i++) {
            string odd = dp(s, i, i);
            string even = dp(s, i, i + 1);
            res = (size(res) > size(odd))? res : odd;
            res = (size(res) > size(even))? res : even;
        }
        
        return res;
    }
};