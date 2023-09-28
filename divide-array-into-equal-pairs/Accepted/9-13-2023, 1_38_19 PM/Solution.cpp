// https://leetcode.com/problems/divide-array-into-equal-pairs

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() % 2 == 1)
            return false;
        for (auto i = 1; i < nums.size(); i += 2) {
            if (nums[i] != nums[i-1])
                return false;
        }
        return true;
    }
};