// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
         if (n == 1)
            return true;
        
        bool check = false;
        
        while (n != 0)
        {
            if (n % 3 != 0)
                return false;
            if (n / 3 == 1)
                return true;      
            
            n = n / 3;
        }
        
        return check;
    }
};