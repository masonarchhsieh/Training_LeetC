// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != i % 2) {
                for (auto j = nums.size() - 1; j >= i; j--) {
                    if (nums[j] % 2 == i % 2) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};