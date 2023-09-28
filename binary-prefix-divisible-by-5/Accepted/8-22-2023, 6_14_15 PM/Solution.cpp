// https://leetcode.com/problems/binary-prefix-divisible-by-5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int n = 0;

        for (int i = 0; i < nums.size(); i++) {
            n = ((n << 1) + nums[i]) % 5;
            res.push_back((n % 5 == 0));
        }

        return res;
    }
};