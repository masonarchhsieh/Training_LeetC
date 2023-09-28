// https://leetcode.com/problems/alternating-digit-sum

class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> v;
        while (n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }
        reverse(v.begin(), v.end());
        int res = 0;
        for (auto i = 0; i < v.size(); i++) {
            if (i % 2 == 0)
                res += v[i];
            else
                res += (-1) * v[i];
        }

        return res;
    }
};