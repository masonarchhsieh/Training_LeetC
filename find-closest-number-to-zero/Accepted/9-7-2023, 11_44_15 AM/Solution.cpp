// https://leetcode.com/problems/find-closest-number-to-zero

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;

        for (auto i : nums) {
            if (abs(i - 0) <= abs(res - 0))
                res = i;
        }
        return res;
    }
};