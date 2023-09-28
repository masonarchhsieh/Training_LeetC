// https://leetcode.com/problems/minimize-string-length

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<char, int> m;
        for (size_t i = 0; i < s.length(); i++)
            m[s[i]]++;
        int res = 0;
        for (auto i : m) {
            res += (i.second >= 2)? 1 : i.second;
        }

        return res;
    }
};