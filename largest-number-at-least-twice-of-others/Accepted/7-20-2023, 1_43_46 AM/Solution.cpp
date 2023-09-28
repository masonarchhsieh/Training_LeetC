// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;

        int res = 0;
        bool correct = true;
        for (unsigned i = 1; i < nums.size(); i++) {
            if (nums[res] == nums[i])
                correct = false;
            else if (nums[res] < nums[i]) {
                if (nums[res] * 2 <= nums[i])
                    correct = true;
                else
                    correct = false;
                res = i;
            } 
            // nums[res] > nums[i]
            else {
                if (nums[i] * 2 > nums[res])
                    correct = false;
            }
        }

        
        return (correct)? res : -1;
    }
};