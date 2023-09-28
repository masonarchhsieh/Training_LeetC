// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0)
            return false;
        if (num == 1)
            return true;
        
        long long left = 0, right = num;
        while (left < right) 
        {
            if (((left + right) / 2) * ((left + right) / 2) == num)
                return true;
            if (((left + right) / 2) * ((left + right) / 2) < num) {
                left = (left + right) / 2 + 1;
            }
            else {
                right = (left + right) / 2;
            }
        }
        return false;
    }
};