// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        int idx = -1;
        
        while (left <= right) {
            mid = (right + left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                idx = mid;
                break;
            }
        }
        
        if (idx == -1)
            return { -1 , -1 };
        
        int start_pos = -1, end_pos = -1;
        for (auto i = idx; i >= 0; i--) {
            if (target == nums[i])
                start_pos = i;
            else
                break;
        }
        for (auto i = idx; i < nums.size(); i++) {
            if (target == nums[i])
                end_pos = i;
            else
                break;
        }
        
        return { start_pos, end_pos };
    }
};