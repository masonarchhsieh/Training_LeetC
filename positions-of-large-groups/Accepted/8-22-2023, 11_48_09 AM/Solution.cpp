// https://leetcode.com/problems/positions-of-large-groups

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int start = 0, end = 0;

        while (start < s.length() - 1) {
            for (end = start + 1; end < s.length(); end++)
                if (s[end] != s[start]) {
                    if (end - start + 1 > 3)
                        res.push_back({start, end - 1});
                    start = end - 1;
                    break;
                }
                else if (end == s.length() - 1 && end - start + 1 >= 3) {
                    res.push_back({start, end });
                    start = end;
                }
            start++;
        }


        return res;
    }
};