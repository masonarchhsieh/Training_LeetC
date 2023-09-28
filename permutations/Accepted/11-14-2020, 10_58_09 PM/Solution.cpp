// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        std::vector<vector<int>>::iterator it;
        it = find(res.begin(), res.end(), nums);
        while (it == res.end()) {
            res.push_back(nums);
            next_permutation(nums.begin(), nums.end());
            it = find(res.begin(), res.end(), nums);
        }
        
        return res;            
    }
};