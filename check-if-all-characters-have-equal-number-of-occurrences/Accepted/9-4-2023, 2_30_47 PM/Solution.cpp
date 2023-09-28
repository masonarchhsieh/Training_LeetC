// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> m;
        for (size_t i = 0; i < s.length(); i++)
            m[s[i]]++;
        int cnt = 0;
        for (auto i : m) {
            if (cnt == 0)
                cnt = i.second;
            if (i.second != cnt)
                return false;
        }
        return true;
    }
};