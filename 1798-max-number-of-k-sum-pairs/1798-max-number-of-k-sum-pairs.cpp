class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ops = 0;
        sort(begin(nums), end(nums));

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] == k) {
                l++;    r--;
                ops++;
            } else if (nums[l] + nums[r] < k)
                l++;
            else if (nums[l] + nums[r] > k)
                r--;
        }

        return ops;
    }
};