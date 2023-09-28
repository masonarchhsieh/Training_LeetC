// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        bool inc = false;
        int res = 0;
        for (int i=1; i<nums.size(); i++) {
            if (inc && nums[i] - nums[i-1] < 0)
                return i-1;
            if (nums[i] - nums[i-1] > 0) {
                inc = true;
                res = i;
            }
            
        }
        
        return res;
    }
};