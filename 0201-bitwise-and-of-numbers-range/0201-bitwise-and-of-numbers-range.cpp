class Solution {
public:
    int rangeBitwiseAnd(unsigned left, unsigned right) {
        while (right > left) {
            right = right & (right - 1);
        }
        return left & right;
    }
};