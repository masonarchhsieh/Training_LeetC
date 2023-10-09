class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin() - 1;
        if (low != nums.size() && nums[low] == target)
            return {low, upper};
        return { -1, -1 };
    }
};