// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        else if (n <= 2)
            return 1;
        
        int f0 = 0, f1 = 1, f2 = 1;
        int res = 0;
        while (n-- > 2) {
            res = f0 + f1 + f2;
            f0 = f1;
            f1 = f2;
            f2 = res;           
        } 
        
        
        return res;
    }
};