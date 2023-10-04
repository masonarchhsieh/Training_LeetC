class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 0;
        int _len = 1;
        for (auto i = 1; i < size(s) && i <= size(s) - res; i++) {
            if (s[i] - s[i-1] != 1) {
                res = max(res, _len);
                _len = 1;
                continue; 
            }
            _len++;
        }

        return max(res, _len);
    }
};