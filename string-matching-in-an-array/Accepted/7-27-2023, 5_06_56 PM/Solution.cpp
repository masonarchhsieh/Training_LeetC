// https://leetcode.com/problems/string-matching-in-an-array

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (auto i = 0; i < words.size(); i ++) {
            for (auto j = 0; j < words.size(); j++) {
                if (i == j)
                    continue;
                if (words[j].find(words[i]) != std::string::npos) {
                    if (find(res.begin(), res.end(), words[i]) == res.end())
                        res.push_back(words[i]);
                }
            }
        }

        return res;
    }
};