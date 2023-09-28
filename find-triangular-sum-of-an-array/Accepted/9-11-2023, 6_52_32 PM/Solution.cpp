// https://leetcode.com/problems/find-triangular-sum-of-an-array

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            for (auto i = 1; i < nums.size(); i++) {
                nums[i-1] = (nums[i-1] + nums[i]) % 10;
            }
            nums.pop_back();
        }
        return nums.front();
    }
};