class Solution {
    const int MODULE_NUM = 1e9 + 7;
public:
    int countNicePairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (auto i : nums)
            res = (res + m[i - rev(i)]++) % MODULE_NUM;

        return res;
    }

    int rev(int n) {
        int rn = 0;
        while (n > 0) {
            rn = 10 * rn + (n % 10);
            n /= 10;
        }
        return rn;
    }
};