// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true, isDecreasing = true;
        for (auto i = 1; i < nums.size(); i++)
            if (nums[i-1] > nums[i]) {
                isIncreasing = false;
                break;
            }
        for (auto i = 1; i < nums.size(); i++)
            if (nums[i-1] < nums[i]) {
                isDecreasing = false;
                break;
            }
        return isIncreasing | isDecreasing;
    }
};