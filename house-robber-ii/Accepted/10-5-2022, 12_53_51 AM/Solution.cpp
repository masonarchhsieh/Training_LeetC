// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        return max(solve(nums, 0, nums.size() - 1), solve(nums, 1, nums.size()));
    }
    
    int solve(vector<int>& nums, int start, int end)
    {
        int prev = nums[start], prev2 = 0;
        for (int i = start + 1; i < end; i++)
        {
            int pick = nums[i] + prev2;
            int npick = prev;
            int curr = max(pick, npick);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};