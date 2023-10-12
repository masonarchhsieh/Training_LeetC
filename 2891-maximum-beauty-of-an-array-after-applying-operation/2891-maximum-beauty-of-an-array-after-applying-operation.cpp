class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        auto l = 0, r = 0;
        for (l = 0, r = 0; r < size(nums); r++) {
            if (nums[r] - nums[l] <= 2 * k) {
                continue;
            }
            // otherwise
            res = max(res, r - l);
            while (nums[r] - nums[l] > 2 * k) {
                l++;
            }
        }
        res = max(res, r - l);

        return res;
    }
};