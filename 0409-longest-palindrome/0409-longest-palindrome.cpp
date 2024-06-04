class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (auto c : s)
            m[c]++;

        int len = 0;
        bool odd_num = false;
        for (auto i = m.begin(); i != m.end(); i++) {
            len += ((*i).second / 2) * 2;
            odd_num |= ((*i).second % 2);
        }

        return len + odd_num;
    }
};