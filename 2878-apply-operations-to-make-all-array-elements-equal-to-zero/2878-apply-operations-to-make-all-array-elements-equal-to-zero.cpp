class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        long long prefixSum = 0;

        for (auto i = 0; i < size(nums); i++) {
            if (prefixSum > nums[i])
                return false;
            nums[i] -= prefixSum;
            prefixSum += nums[i];
            if (i >= k - 1)
                prefixSum -= nums[i - k + 1];
        }
        return (prefixSum == 0);
    }
};