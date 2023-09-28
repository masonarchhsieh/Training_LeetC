// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> m;
        int n = words.size();
        for (auto i : words) {
            for (auto j = 0; j < i.length(); j++)
                m[i[j]]++;
        }
        for (auto i : m)
            if (i.second % n != 0)
                return false;

        return true;
    }
};