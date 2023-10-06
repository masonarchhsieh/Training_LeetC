class Solution {
public:
    int characterReplacement(string s, int k) {
        int localmax = 0;
        int res = 0;
        unordered_map<char, int> m;

        for (auto l = 0, r = 0; r < size(s); r++) {
            m[s[r]]++;
            localmax = max(localmax, m[s[r]]);

            if ((r - l + 1) - localmax > k) {
                m[s[l++]]--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};