class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, sum = 0;
        for (auto l = 0, r = 0; r < size(s); r++) {
            sum += abs(s[r] - t[r]);

            while (sum > maxCost) {
                sum -= abs(s[l] - t[l]);
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};