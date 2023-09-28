// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int pos = n - 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (pos <= i + nums[i])
                pos = i;
        }
        
        return pos == 0;
    }
};