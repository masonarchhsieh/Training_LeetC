// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n == 1)
            return true;
        
        bool check = false;
        
        while (n != 0)
        {
            if (n % 2 != 0)
                return false;
            if (n / 2 == 1)
                return true;      
            
            n = n / 2;
        }
        
        return check;
    }
};