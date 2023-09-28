// https://leetcode.com/problems/minimum-distance-to-the-target-element

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {        
        int res = INT_MAX;
        
        for (int i=0; i<nums.size(); i++)
            if (nums[i] == target)
                res = (res < abs(i - start))? res : abs(i - start);
        
        return res;
    }
};