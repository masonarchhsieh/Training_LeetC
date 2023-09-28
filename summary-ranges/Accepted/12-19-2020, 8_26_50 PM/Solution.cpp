// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() <= 0)
            return res;
        
        for (int i=0; i<nums.size(); i++) {
            int j=i;
            while ( j+1 < nums.size() && (long) ((long)nums[j+1] - (long)nums[j]) == 1)
                j++;
            
            if (i == j)
                res.push_back(to_string(nums[i]));
            else
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            
            i = j;
            
        }
        
        return res;
    }
};