// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        return max(upper_bound(nums.begin(), nums.end(), -1) - nums.begin(),
                nums.end() - upper_bound(nums.begin(), nums.end(), 0));
    }
};