class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (size(nums) <= 4)
            return 0;

        int n = size(nums);
        sort(nums.begin(), nums.end());

        return min(abs(nums[0] - nums[n - 4]),
                min(abs(nums[1] - nums[n - 3]), 
                    min(abs(nums[2] - nums[n - 2]), abs(nums[3] - nums[n - 1]))));
    }
};