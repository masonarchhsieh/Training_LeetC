class Solution {
public:
    int appendCharacters(string s, string t) {
        auto l = 0, r = 0;

        while (l < s.length() && r < t.length()) {
            r += (s[l] == t[r]);
            l++;
        }
        
        return t.length() - r;
    }
};