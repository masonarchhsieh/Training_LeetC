// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int orig_size = nums.size();
        int count = 0, itr = 0;

        while (++count < orig_size) {
            if (nums[itr] == 0) {
                nums.erase(nums.begin() + itr);
                nums.push_back(0);
            }
            else
                itr++;
        }
    }
};