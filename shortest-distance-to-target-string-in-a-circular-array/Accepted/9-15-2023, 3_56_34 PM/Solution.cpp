// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int res = -1;
        vector<string> t(words);
        if (find(words.begin(), words.end(), target) == words.end())
            return res;

        words.insert(words.end(), t.begin(), t.end());

        for (auto i = startIndex; i < words.size(); i++) {
            if (words[i] == target) {
                res = i - startIndex;
                break;
            }
        }

        for (auto i = startIndex + words.size() / 2; i >= 0; i--) {
            if (words[i] == target) {
                res = min(res, (int) (startIndex + words.size() / 2 - i));
                break;
            }
        }

        return res;
    }
};