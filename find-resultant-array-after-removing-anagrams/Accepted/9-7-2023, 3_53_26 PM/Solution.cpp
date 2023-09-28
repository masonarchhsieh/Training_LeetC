// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

bool Sort(const char &a, const char &b) {
    return a <= b;
}
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);

        for (auto i = 1; i < words.size(); i++) {
            unordered_map<char, int> m;
            if (words[i].length() != words[i-1].length()) {
                res.push_back(words[i]);
                continue;
            }
            for (size_t j = 0; j < words[i-1].length(); j++) {
                if (count(words[i].begin(), words[i].end(), words[i-1][j]) != count(words[i-1].begin(), words[i-1].end(), words[i-1][j])) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};