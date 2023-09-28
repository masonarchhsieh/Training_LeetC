// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        
        int res = 3;
        int step1 = 1, step2 = 2;
        while (n-- > 2) {
            res = step1 + step2;
            step1 = step2;
            step2 = res;
        }
        
        return res;
        
    }
};