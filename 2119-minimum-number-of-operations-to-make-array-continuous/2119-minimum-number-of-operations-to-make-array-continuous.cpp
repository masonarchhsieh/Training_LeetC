class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = unique(nums.begin(), nums.end());
        int uniqLen = distance(nums.begin(), it);

        int ops = size(nums);
        for (auto l = 0, r = 0; l < size(nums); l++) {
            while (r < uniqLen && nums[r] - nums[l] <= size(nums) - 1) {
                r++;
            }
            ops = min(ops, (int) size(nums) - (r - l));
        }

        return ops;
    }
};