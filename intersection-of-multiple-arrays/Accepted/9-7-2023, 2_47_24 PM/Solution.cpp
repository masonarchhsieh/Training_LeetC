// https://leetcode.com/problems/intersection-of-multiple-arrays

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, bool> digits;
        for (auto i : nums[0])
            digits[i] = true;
        
        for (auto &d : digits) {
            for (auto i = 1; i < nums.size(); i++) {
                if (find(nums[i].begin(), nums[i].end(), d.first) == nums[i].end()) {
                    d.second = false;
                    break;
                }
            }
        }

        vector<int> res;
        for (auto d : digits) {
            if (d.second)
                res.push_back(d.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};