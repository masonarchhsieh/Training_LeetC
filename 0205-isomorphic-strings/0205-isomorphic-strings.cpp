class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;

        for (auto i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] == t[i])
                    continue;
                return false;
            }
            for (auto c : m) {
                if (c.second == t[i])
                    return false;
            }
            m[s[i]] = t[i];
        }

        return true;
    }
};