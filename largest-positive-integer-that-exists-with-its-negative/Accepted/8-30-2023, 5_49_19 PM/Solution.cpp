// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto i = nums.end() - 1; i >= nums.begin(); i--) {
            if (find(nums.begin(), nums.end(), -*i) != nums.end())
                return *i;
        }
        return -1;
    }
};