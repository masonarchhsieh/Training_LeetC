class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        vector<int> diff_v(s.length(), 0);
        for (auto i = 0; i < size(s); i++)
            diff_v[i] = abs(s[i] - t[i]);

        int sum = 0;
        for (auto l = 0, r = 0; r < size(diff_v); r++) {
            sum += diff_v[r];

            while (sum > maxCost) {
                sum -= diff_v[l++];
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};