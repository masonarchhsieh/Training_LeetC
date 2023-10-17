class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = size(nums);
        vector<int> res(n, 0);

        int products = 1;
        for (auto i = 0; i < n; i++) {
            res[i] = products;
            products *= nums.at(i);
        }

        products = 1;
        for (auto i = n - 1; i >= 0; i--) {
            res[i] = (res[i] * products);
            products = products * nums.at(i);
        }

        return res;
    }
};