// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
    map<char, int> ballons = {
        {'b', 1},
        {'a', 1},
        {'l', 2},
        {'o', 2},
        {'n', 1}
    };
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for (size_t i = 0; i < text.length(); i++)
            m[text[i]]++;
        int res = INT_MAX;
        for (auto i : ballons) {
            if (m[i.first] == 0)
                return 0;
            res = min(res, m[i.first] / i.second);
        }
        return res;
    }
};