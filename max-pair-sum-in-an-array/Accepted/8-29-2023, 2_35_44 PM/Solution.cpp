// https://leetcode.com/problems/max-pair-sum-in-an-array

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = -1;
        for (auto i = 0; i < nums.size(); i++) {
            int d1 = findMaxDigit(nums[i]);
            for (auto j = i + 1; j < nums.size(); j++) {
                if (d1 == findMaxDigit(nums[j]))
                    res = max(res, nums[i] + nums[j]);
            }
        }
        return res;
    }

    int findMaxDigit(int num) {
        int digit = 0;
        while (num > 0) {
            digit = max(digit, num % 10);
            num /= 10;
        }
        return digit;
    }
};