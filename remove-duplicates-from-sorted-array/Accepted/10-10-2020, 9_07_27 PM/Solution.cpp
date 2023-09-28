// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int itr = 0;
        
        while (itr < nums.size())
        {
            int i=itr+1;
            while (i<nums.size())
            {
                if (nums[itr] == nums[i])
                {
                    nums.erase(nums.begin() + i);
                }
                else
                    i++;
            }
            itr++;
        }
             
        return nums.size();
    }
};