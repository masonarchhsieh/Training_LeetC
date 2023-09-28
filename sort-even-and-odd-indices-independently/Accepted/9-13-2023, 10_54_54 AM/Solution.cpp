// https://leetcode.com/problems/sort-even-and-odd-indices-independently

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        //Sort the values at odd indices of nums in non-increasing order
        for (auto i = 1; i < nums.size(); i+=2) {
            for (auto j = i + 2; j < nums.size(); j+=2) {
                if (nums[i] < nums[j])
                    swap(nums[i], nums[j]);
            }
        }
        //Sort the values at even indices of nums in non-decreasing order
        for (auto i = 0; i < nums.size(); i+=2) {
            for (auto j = i + 2; j < nums.size(); j += 2) {
                if (nums[i] > nums[j])
                    swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};