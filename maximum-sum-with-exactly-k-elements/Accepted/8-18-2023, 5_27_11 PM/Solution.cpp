// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (auto i = 0; i < k; i++) {
            res += nums[nums.size() - 1];
            nums[nums.size() - 1]++;
        }
        return res;
    }
};