// https://leetcode.com/problems/left-and-right-sum-differences

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res;
        int right_sum = accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        for (auto i = 0; i < nums.size(); i++) {
            right_sum -= nums[i];
            res.push_back(abs(right_sum - left_sum));
            left_sum += nums[i];
        }


        return res;
    }
};