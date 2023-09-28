// https://leetcode.com/problems/sum-of-all-subset-xor-totals

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        dfs(0, nums, 0, ans, n);
        return ans;
    }

    void dfs(int idx, vector<int>& nums, int sums, int &ans, int n) {
        if (idx == n) {
            ans += sums;
            return;
        }
        // take
        dfs(idx + 1, nums, sums ^ nums[idx], ans, n);
        // not take
        dfs(idx + 1, nums, sums, ans, n);
    }
};