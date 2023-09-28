// https://leetcode.com/problems/combination-sum-ii


class Solution {
    set<vector<int>> res_s;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        // if (accumulate(candidates.begin(), candidates.end(), 0) < target)
        //     return res;
        backtrack(candidates, {}, 0, target);

        res.insert(res.end(), res_s.begin(), res_s.end());
        return res;
    }

    void backtrack(vector<int>& candidates, vector<int> combination, int pos, int target) {
        if (target == 0) {
            res_s.insert(combination);
            return;
        }
        if (pos >= candidates.size() || target < 0)
            return;
        
        for (auto i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;

            combination.push_back(candidates[i]);
            backtrack(candidates, combination, i + 1, target - candidates[i]);
            combination.pop_back();
        }
    }
};