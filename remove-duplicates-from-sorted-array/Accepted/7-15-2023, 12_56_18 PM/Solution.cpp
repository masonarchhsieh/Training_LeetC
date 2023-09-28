// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it;

        it = unique(nums.begin(), nums.end());
        return (int) (it - nums.begin());
    }
};