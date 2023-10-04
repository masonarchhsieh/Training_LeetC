class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> m;
        int res = 0;
        int i = 0;
        for (size_t j = 0; j < s.length(); j++) {
            m[s[j]]++;
            while (consistABC(m)) {
                res += (s.length() - j);
                m[s[i]]--;
                i++;
            }
        }

        return res;
    }

    bool consistABC(unordered_map<char, int>& m) {
        return m['a'] > 0 && m['b'] > 0 && m['c'] > 0;
    }
};