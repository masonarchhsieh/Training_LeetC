// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
     
        sort(nums.begin(), nums.end());
        
        int dup = 0;
        if (k != 0)
            nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=i+1; j<nums.size();j++) {
                if (k == 0 && nums[j] == nums[i])
                    dup++;
                else
                    dup = 0;
                
                if (nums[j] - nums[i] == k && dup <= 1)
                    res++;
                
                if (nums[j] - nums[i] == k && dup > 1)
                    i = j;
            }
        }
        
        
        return res;
    }
};