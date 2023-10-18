class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> m;
        int res = 0;
        for (auto i : tiles)
            m[i]++;
        helper(m, 0, res, size(tiles));
        return res - 1;                 // shouldn't count the empty("") result
    }

    void helper(unordered_map<char, int>& m, int level, int& res, int len) {
        res++;
        if (level == len)
            return;
        
        for (auto& c : m) {
            if (c.second != 0) {
                c.second--;
                helper(m, level + 1, res, len);
                c.second++;
            }
        }
    }
};