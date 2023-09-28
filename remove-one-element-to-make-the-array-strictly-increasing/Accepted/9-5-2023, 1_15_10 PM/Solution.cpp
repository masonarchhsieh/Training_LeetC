// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        return helper(nums, true);
    }

    bool helper(vector<int>& nums, bool removable) {
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                if (removable) {
                    vector<int> tmp1 = nums, tmp2 = nums ;
                    tmp1.erase(tmp1.begin() + i);
                    tmp2.erase(tmp2.begin() + i - 1);

                    return helper(tmp1, false) | helper(tmp2, false);
                }
                return false;
            }
        }

        return true;
    }
};