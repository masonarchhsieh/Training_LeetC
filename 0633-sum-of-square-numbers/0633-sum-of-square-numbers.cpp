class Solution {
public:
    bool judgeSquareSum(long long c) {
        long long right = static_cast<long long>(sqrt(c));
        long long left = 0;

        while (left <= right) {
            if (left * left + right * right == c)
                return true;
            else if (left * left + right * right > c) {
                right--;
            } else
                left++;
        }

        return false;
    }
};