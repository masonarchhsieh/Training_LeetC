// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;

        for (auto i = 1; i < n; i++) {
            string a = to_string(i), b = to_string(n - i);
            if (a.find('0') != std::string::npos || b.find('0') != std::string::npos)
                continue;
            res = { i, n - i};
        }

        return res;
    }
};