// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt_neg = 0, sum = 0;
        for (auto i = 0; i < nums.size() && nums[i] < 0; i++)
            cnt_neg = i + 1;
        for (auto i = 0; i < k && i < cnt_neg; i++)
            nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end());

        if (k > cnt_neg) {
            int sign = ((k - cnt_neg) % 2 == 0)? 1 : -1;
            nums[0] *= sign;
        }

        for (auto i : nums)
            sum += i;
        return sum;
    }
};