// https://leetcode.com/problems/maximum-ascending-subarray-sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = nums[0];
        int tmp = nums[0];
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                max_sum = max(max_sum, tmp);
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
        }
        max_sum = max(max_sum, tmp);
        return max_sum;
    }
};