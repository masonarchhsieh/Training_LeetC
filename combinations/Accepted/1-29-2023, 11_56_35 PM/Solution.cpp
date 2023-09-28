// https://leetcode.com/problems/combinations

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(temp, n, k, 1);

        return ans;
    }

    void backtrack(vector<int> &combs, int n, int k, int start) {
        if (combs.size() > k)
            return;
        if (combs.size() == k)
            ans.push_back(combs);
        
        for (auto i = start; i<=n; i++) {
            combs.push_back(i);
            backtrack(combs, n, k, i + 1);
            combs.pop_back();
        }
    }
};