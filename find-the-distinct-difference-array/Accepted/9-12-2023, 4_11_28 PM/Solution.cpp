// https://leetcode.com/problems/find-the-distinct-difference-array

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> f, all;
        for (auto i : nums)
            all.insert(i);
        
        for (auto i = 0; i < nums.size(); i++) {
            f.insert(nums[i]);
            if (find(nums.begin() + i + 1, nums.end(), nums[i]) == nums.end())
                all.erase(nums[i]);
            res.push_back(f.size() - all.size());
        }
        return res;
    }
};