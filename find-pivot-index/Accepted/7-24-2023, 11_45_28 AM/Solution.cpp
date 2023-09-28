// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums)
            sum += i;

        int pivot = -1;
        int left_sum = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (left_sum * 2 == sum - nums[i])
                return i;
            left_sum += nums[i];
        }
        return pivot;
    }
};