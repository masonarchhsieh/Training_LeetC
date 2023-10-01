class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> w1_map, w2_map;
        int n = word1.length();

        for (auto i = 0; i < n; i++) {
            w1_map[word1[i]]++;
            w2_map[word2[i]]++;
        }
        int res = 0;
        for (auto i : w1_map) {
            if (w2_map.find(i.first) == w2_map.end()) {
                res = max(res, i.second);
            } else {
                res = max(res, (i.second > w2_map[i.first])?
                    (i.second - w2_map[i.first]) : 0);
            }
        }
        for (auto i : w2_map) {
            if (w1_map.find(i.first) == w1_map.end()) {
                res = max(res, i.second);
            } else {
                res = max(res, (i.second > w1_map[i.first])?
                    (i.second - w1_map[i.first]) : 0);
            }
        }
        return res <= 3;
    }
};