// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (auto i = 1; i < words.size(); i++) {
            for (auto j = 0; j < words[i].size() && j < words[i-1].size(); j++) {
                if (order.find(words[i][j]) > order.find(words[i-1][j]))
                    break;
                if (order.find(words[i][j]) < order.find(words[i-1][j])) {
                    return false;
                }
                if (j == words[i].size() - 1 && j < words[i-1].size() - 1) {
                    return false;
                }
            }
        }

        return true;
    }
};