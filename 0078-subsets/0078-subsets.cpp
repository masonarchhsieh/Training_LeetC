class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, {}, 0);
        return res;
    }

    void helper(vector<int>& nums, vector<int> v, int i) {
        if (i >= nums.size()) {
            res.push_back(v);
            return;
        }
        v.push_back(nums.at(i));
        helper(nums, v, i + 1);
        v.pop_back();
        helper(nums, v, i + 1);
    }

};