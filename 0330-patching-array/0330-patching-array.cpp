class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long candidate = 1;
        int patches = 0;
        int i = 0;

        while (candidate <= n) {
            if (i < size(nums) && nums[i] <= candidate) {
                candidate += nums[i];
                i++;
            } else {
                candidate += candidate;
                patches++;
            }
        }

        return patches;
    }
};