// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            mid = left + (right - left) / 2;

            if (nums.at(mid) == target)
                return true;
            // duplicates
            if (nums.at(left) == nums.at(right) && nums.at(left) == nums.at(mid)) {
                left++;
                right--;
            }
            else if (nums.at(left) <= nums.at(mid)) {
                if (nums.at(left) <= target && nums.at(mid) > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // nums.at(left) > nums.at(mid)
            else {
                if (nums.at(mid) < target && nums.at(right) >= target) {
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            } 
        }


        return false;
    }
};