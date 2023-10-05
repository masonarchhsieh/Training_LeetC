class Solution {
public:
    int findMin(vector<int>& nums) {
        return nums[(min_element(nums.begin(), nums.end()) - nums.begin())];
    }
};