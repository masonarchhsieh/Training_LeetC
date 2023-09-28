// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == target)
                return i;
            if (nums[i] > target)
                return -1;
        }
        
        return -1;
    }
};