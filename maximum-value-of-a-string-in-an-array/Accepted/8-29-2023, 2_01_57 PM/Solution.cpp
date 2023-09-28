// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array

#include <string>
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = INT_MIN;
        for (auto i : strs) {
            bool isNum = true;
            int tmp = 0;
            for (auto j = 0; j < i.length(); j++) {
                if (!isdigit(i[j])) {
                    isNum = false;
                    res = max(res, (int)i.length());
                    break;
                }
                tmp = (tmp * 10) + (i[j] - '0');
            }
            if (isNum) {
                res = max(res, tmp);
            }
        }

        return res;
    }
};