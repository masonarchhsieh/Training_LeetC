// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        
        for (int i=nums.size()-2; i>=0; i--) {
            for (int j=nums.size()-1; j>i; j--) {
                if (nums[i] < nums[j]) {
                    int t = nums[i];
                    nums[i] = nums[j];
                    nums[j] = t;
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        sort(nums.begin(), nums.end());
    }
};