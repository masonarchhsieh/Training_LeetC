// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ele_sum = 0, digit_sum = 0;

        for (auto i : nums) {
            ele_sum += i;
            while (i > 0) {
                digit_sum += (i % 10);
                i /= 10;
            }
        }
        return abs(ele_sum - digit_sum);
    }
};