// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for (auto i = -n/2; i <= n/2; i++) {
            if (i == 0)
                continue;
            res.push_back(i);
        }
        if (n % 2)
            res.push_back(0);

        return res;
    }
};