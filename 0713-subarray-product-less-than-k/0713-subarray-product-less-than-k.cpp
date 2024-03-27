class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        
        int res = 0;
        int product = 1, left = 0, right = 0;
        
        while (right < nums.size()) {
            product *= nums[right++];
            while (left < nums.size() && product >= k) {
                product /= nums[left++];
            }
            res += right - left;
        }
        
        return res;
    }
};