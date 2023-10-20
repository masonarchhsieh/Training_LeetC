class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const string space = " ";
        string res;
        int idx = 0, n = size(spaces);

        for (auto i = 0; i < s.length(); i++) {
            if (idx < n && i == spaces[idx]) {
                res += space;
                idx++;
            }
            res += s[i];
        }

        return res;
    }
};