// https://leetcode.com/problems/find-the-pivot-integer

class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1)
            return 1;
        int left_sum = 0, right_sum = 0;
        for (auto i = 1; i < n; i++) {
            left_sum += i;
            right_sum = 0; 
            for (auto j = i; j <= n; j++)
                right_sum += j;
            if (left_sum == right_sum) {
                return i;
            }
        }

        return -1;
    }
};