// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = (nums.size() < 2)? nums.size() : 0, left = 0, right = 1;

        while (left < nums.size() && right < nums.size()) {
            
            if (nums[right] <= nums[right - 1]) {
                left = right;
            }
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};