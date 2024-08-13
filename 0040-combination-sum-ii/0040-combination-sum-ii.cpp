class Solution {
    set<vector<int>> _set;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        backtrack(candidates, {}, 0, target);
        return vector<vector<int>>(_set.begin(), _set.end());
    }

    void backtrack(vector<int>& candidates, vector<int> combination, int pos, int target) {
        if (target == 0) {
            _set.insert(combination);
            return;
        }
        if (pos >= size(candidates) || target < 0)
            return;
        for (auto i = pos; i < size(candidates); i++) {
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