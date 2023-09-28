// https://leetcode.com/problems/neither-minimum-nor-maximum

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[(0 + nums.size()) / 2] != nums.front() && nums[(0 + nums.size()) / 2] != nums.back())
            return nums[(0 + nums.size()) / 2];

        return -1;
    }
};