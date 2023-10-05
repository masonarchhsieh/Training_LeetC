class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subArrayLessThanGoal(nums, goal) - subArrayLessThanGoal(nums, goal - 1);
    }

    int subArrayLessThanGoal(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int res = 0, current_sum = 0;
        for (auto l = 0, r = 0; r < nums.size(); r++) {
            current_sum += nums[r];
            while (current_sum > goal) {
                current_sum -= nums[l++];
            }
            res += (r - l + 1);
        }
        return res;
    }
};