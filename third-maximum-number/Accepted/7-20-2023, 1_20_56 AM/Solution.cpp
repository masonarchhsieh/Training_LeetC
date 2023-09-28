// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        
        if (nums.size() < 3)
            return nums[nums.size() - 1];
        
        return nums[nums.size() - 3];
    }
};