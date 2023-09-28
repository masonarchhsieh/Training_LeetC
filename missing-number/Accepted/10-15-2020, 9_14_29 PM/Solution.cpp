// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        
        std::sort(nums.begin(), nums.end());
        if (nums[0] != 0)
            return 0;
        
        for (int i=1; i<nums.size() && i >= 1; i++) {
            if (nums[i] - nums[i-1] > 1)
                return (int) (nums[i] + nums[i-1]) / 2;
        }
        
        return res;
    }
};