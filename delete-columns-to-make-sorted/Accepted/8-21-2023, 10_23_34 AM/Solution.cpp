// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;

        for (auto i = 0; i < strs[0].length(); i++) {
            for (auto j = 1; j < strs.size(); j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};