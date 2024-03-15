class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = size(nums);
        vector<int> res(n, 0);

        int prod = 1;
        for (auto i = 0; i < n; i++) {
            res[i] = prod;
            prod *= nums[i];
        }

        prod = 1;
        for (auto i = n - 1; i >= 0; i--) {
            res[i] = (res[i] * prod);
            prod = prod * nums[i];
        }

        return res;
    }
};