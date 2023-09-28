// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helper(0, nums, ds, res);
        return res;
    }
    
    void helper(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            if (find(res.begin(), res.end(), ds) == res.end())
                res.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        helper(idx + 1, nums, ds, res);
        ds.pop_back();
        helper(idx + 1, nums, ds, res);
    }
};