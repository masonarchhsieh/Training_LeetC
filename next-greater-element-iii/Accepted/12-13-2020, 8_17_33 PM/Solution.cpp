// https://leetcode.com/problems/next-greater-element-iii

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int num = n;
        while (num > 0) {
            digits.push_back(num % 10);
            num = num / 10;
        }
        reverse(digits.begin(), digits.end());
        next_permutation(digits.begin(), digits.end());
        
        long res = 0;
        for (int i=0; i<digits.size(); i++) {
            res = res * 10 + digits[i];
        }
        return (res > n && res < INT_MAX) ? res : -1;
    }
};