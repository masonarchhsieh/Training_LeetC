class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for (auto c : s)
            m[c]++;

        string res(s.length(), '0');
        int itr = 0;
        for (auto i : order) {
            if (m.find(i) != m.end()) {
                for (itr; itr < s.length() && m[i] > 0; itr++) {
                    m[i]--;
                    res[itr] = i;
                }
            }
        }

        for (auto &i : m) {
            for (auto j = 0; j < i.second && itr < res.length(); j++) {
                res[itr++] = i.first;
            }
        }
        return res;
    }
};