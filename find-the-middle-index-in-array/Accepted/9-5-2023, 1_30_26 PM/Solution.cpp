// https://leetcode.com/problems/find-the-middle-index-in-array

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum_r = accumulate(nums.begin(), nums.end(), 0);
        int sum_l = 0;
        for (auto i = 0; i < nums.size(); i++) {
            sum_r -= nums[i]; 
            if (sum_r == sum_l)
                return i;
            sum_l += nums[i];   
        }

        return -1;
    }
};
