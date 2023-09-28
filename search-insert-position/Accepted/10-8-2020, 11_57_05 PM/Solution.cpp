// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int itr = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
            if (nums[i] < target)
                itr = i;
        }
        
        return (target < nums[itr])? 0: itr + 1;
    }
};