// https://leetcode.com/problems/find-greatest-common-divisor-of-array

class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto i = nums[0]; i >= 0; i--) {
            if (nums[nums.size() - 1] % i == 0 && nums[0] % i == 0)
                return i;
        }
        return 1;
    }
};