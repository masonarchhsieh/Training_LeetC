// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits

class Solution {
public:
    int minimumSum(int num) {
        int res = INT_MAX;
        vector<int> v;
        while (num > 0) {
            v.push_back(num % 10);
            num /= 10;
        }
        sort(v.begin(), v.end());

        return v[0] * 10 + v[1] * 10 + v[2] + v[3];
    }
};