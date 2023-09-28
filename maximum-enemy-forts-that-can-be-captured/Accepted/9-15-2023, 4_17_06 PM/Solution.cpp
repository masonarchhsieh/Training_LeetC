// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int res = 0;

        for (auto i = 0; i < forts.size() - 1; i++) {
            if (abs(forts[i]) == 1) {
                auto j = i + 1;
                while (j < forts.size() - 1 && abs(forts[j]) != 1) {
                    j++;
                }
                if (forts[j] == 0)
                    break;
                if (forts[j] != forts[i]) {
                    res = max(res, j - i + 1 - 2);
                }
            }
        }

        return res;
    }
};