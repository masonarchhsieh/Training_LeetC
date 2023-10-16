class Solution {
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack({}, 0, k, n);
        return res;
    }

    void backtrack(vector<int> v, int idx, int k, int n) {
        if (k == 0 && n == 0) {
            res.push_back(v);
            return;
        }
        if (k <= 0)
            return;
        if (n <= 0)
            return;
        if (idx >= size(nums))
            return;
        v.push_back(nums.at(idx));
        backtrack(v, idx + 1, k - 1, n - nums.at(idx));
        v.pop_back();
        backtrack(v, idx + 1, k, n);
    }
};