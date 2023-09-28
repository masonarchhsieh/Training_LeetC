// https://leetcode.com/problems/smallest-range-i

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        if (abs(nums[nums.size() - 1] - nums[0]) <= k * 2)
            return 0;
        
        return nums[nums.size() - 1] - nums[0] - k * 2;
    }
};