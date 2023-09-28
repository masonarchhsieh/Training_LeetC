// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dup = 0, target = nums.size();
        if (nums[0] != 1)
            target = 1;
        
        for (int i=1; i<nums.size(); i++) {
            if (nums[i-1] == nums[i]) {
                dup = nums[i];
            }
            else if (nums[i] - nums[i-1] > 1) {
                target = (int) ((nums[i] + nums[i-1]) / 2);
            }
        }
        
        vector<int> res;
        res.push_back(dup);
        res.push_back(target);
        
        return res;
    }
};