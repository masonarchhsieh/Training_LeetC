// https://leetcode.com/problems/number-of-distinct-averages

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int res = 0;
        if (nums.size() == 0)
            return 0;
        unordered_set<int> s;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size() / 2; i++) {
            s.insert((nums[i] + nums[nums.size() - 1 - i]));
        }
        return s.size();
    }
};