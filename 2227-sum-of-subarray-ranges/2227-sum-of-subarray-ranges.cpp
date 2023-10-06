class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;

        for (auto start = 0; start < size(nums); start++) {
            int minElement = nums[start];
            int maxElement = nums[start];
            for (auto i = start + 1; i < size(nums); i++) {
                minElement = min(minElement, nums[i]);
                maxElement = max(maxElement, nums[i]);
                res += maxElement - minElement;
            }
        }
        return res;
    }
};