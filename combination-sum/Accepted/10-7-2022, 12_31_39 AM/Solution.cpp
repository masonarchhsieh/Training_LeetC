// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        helper(target, 0, candidates, ds, ans);
        vector<vector<int>>::iterator it = unique(ans.begin(), ans.end());
        ans.resize(std::distance(ans.begin(), it));
        
        return ans;
    }
    
    void helper(int target, int idx, vector<int>& candidates, vector<int> ds, vector<vector<int>>& ans) {
        //int sum = std::accumulate(ds.begin(), ds.end(), 0);
        //std::cout << sum << std::endl;
        if (std::accumulate(ds.begin(), ds.end(), 0) > target || idx >= candidates.size())
            return;
        if (std::accumulate(ds.begin(), ds.end(), 0) == target) {
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(candidates[idx]);
        helper(target, idx, candidates, ds, ans);
        ds.pop_back();
        helper(target, idx + 1, candidates, ds, ans);      
    }
};