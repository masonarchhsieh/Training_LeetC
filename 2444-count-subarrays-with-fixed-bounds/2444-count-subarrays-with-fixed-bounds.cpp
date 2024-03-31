class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int start = 0;
        int minIndex = -1, maxIndex = -1;
        for (auto i = 0; i < size(nums); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                minIndex = -1, maxIndex = -1;
                start = i + 1;
            }
            if (nums[i] == minK)
                minIndex = i;
            if (nums[i] == maxK)
                maxIndex = i;
            res += max(0, min(minIndex, maxIndex) - start + 1);
        }

        return res;
    }
};