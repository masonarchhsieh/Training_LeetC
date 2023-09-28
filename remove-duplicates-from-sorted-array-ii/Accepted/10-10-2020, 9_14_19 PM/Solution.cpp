// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int itr = 0;
        bool first = false;
        
        while (itr < nums.size())
        {
            
            int i = itr + 1;
            int count = 1;
            while (i<nums.size())
            {
                if (count >= 2 && nums[itr] == nums[i])
                {
                    nums.erase(nums.begin() + i);
                }
                else 
                {
                    if (nums[itr] == nums[i])
                        count++;
                    i++;
                }
            }
            
            itr++;
        }
        
        
        
        return nums.size();
    }
};