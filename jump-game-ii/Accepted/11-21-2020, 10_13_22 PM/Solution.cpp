// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {       
        int itr = 0;
        int res = 0;
        
        if (nums.size() == 1)
            return 0;
        
        while (itr < nums.size() && nums[itr] != 0) {
            if (nums[itr] == 0)
                return -1;
            if (itr + nums[itr] >= nums.size()-1)
                return res + 1;
            
            int next = itr + nums[itr];
            for (int i=itr; i<=itr+nums[itr] && i<nums.size(); i++) {
                if (next + nums[next] <= i + nums[i]) {
                    next = i;
                }
            }
            
            itr = next;
            res++;
        }
        
        return -1;
    }
};