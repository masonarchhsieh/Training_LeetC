class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0, r = 0;
        int cur_sum = 0;
        int ops = INT_MAX;
        int sum_of_array = accumulate(nums.begin(), nums.end(), 0);
        if (sum_of_array < x)
            return -1;
        x = sum_of_array - x;

        while (r < size(nums)) {
            cur_sum += nums[r++];
            while (cur_sum > x && l < size(nums))
                cur_sum -= nums[l++];

            if (cur_sum == x)
                ops = min(ops, (int) size(nums) - r + l);
        }
        return (ops == INT_MAX)? -1 : ops;
    }
};