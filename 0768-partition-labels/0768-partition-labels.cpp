class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> m;
        for (auto i = 0; i < size(s); i++)
            m[s[i]] = i;

        int idx = 0;

        while (idx < size(s)) {
            int last_idx = m[s[idx]];

            for (auto j = 0; j < last_idx; j++) {
                last_idx = max(last_idx, m[s[j]]);
            }
            res.push_back(last_idx - idx + 1);
            idx = last_idx + 1;
        }

        return res;
    }
};