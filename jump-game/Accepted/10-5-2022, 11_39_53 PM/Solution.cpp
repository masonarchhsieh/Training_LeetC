// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        
        int itr = 0;
        
        while (itr < nums.size() && nums[itr] != 0) {
            if (nums[itr] == 0)
                return false;
            if (itr + nums[itr] >= nums.size()-1)
                return true;
            
            int next = itr + nums[itr];
            for (int i=itr; i<=itr+nums[itr] && i<nums.size(); i++) {
                if (next + nums[next] <= i + nums[i]) {
                    next = i;
                }
            }
            
            itr = next;
        }
        
        return false;
    }
};