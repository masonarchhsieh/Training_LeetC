// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());

        for (auto i = 0; i <= nums.size() - k; i++) {
            diff = min(diff, nums[i + k - 1] - nums[i]);
        }

        return diff;
    }
};