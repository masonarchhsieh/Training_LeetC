class Solution {
public:
    string longestNiceSubstring(string s) {
        unordered_map<char, int> m;
        string res;
        int n = s.length();

        for (size_t i = 0; i < n; i++) {
            string tmp;
            for (auto j = i; j < n; j++) {
                m[s[j]]++;
                tmp.push_back(s[j]);
                if (isNiceString(m))
                    res = (res.length() >= tmp.length())? res : tmp;
            }
            m.clear();
        }

        return res;
    }

    bool isNiceString(unordered_map<char, int>& m) {
        for (auto i : m) {
            if (i.second == 0)
                continue;
            if (islower(i.first)) {
                if (m.find(toupper(i.first)) == m.end())
                    return false;
                if (m[toupper(i.first)] == 0)
                    return false;
            }
            if (isupper(i.first)) {
                if (m.find(tolower(i.first)) == m.end())
                    return false;
                if (m[tolower(i.first)] == 0)
                    return false;
            }
        }
        return true;
    }
};