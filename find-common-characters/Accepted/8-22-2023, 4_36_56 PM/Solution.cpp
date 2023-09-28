// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> m;
        vector<string> res;
        for (auto i = 0; i < words[0].length(); i++)
            m[words[0][i]]++;
        for (auto i = 1; i < words.size(); i++)
            for (auto w = m.begin(); w != m.end(); w++)
                if (count(words[i].begin(), words[i].end(), w->first) < w->second)
                    w->second = count(words[i].begin(), words[i].end(), w->first);

        for (auto i : m) {
            for (auto j = 0; j < i.second; j++) {
                string tmp(1, i.first);
                res.push_back(tmp);
            }
        }

        return res;
    }
};