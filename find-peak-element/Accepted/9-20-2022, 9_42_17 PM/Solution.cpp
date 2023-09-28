// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return (int) (max_element(nums.begin(), nums.end()) - nums.begin());
    }
};