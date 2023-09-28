// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int num) {
         if (num == 1)
            return true;
        
        bool check = false;
        
        while (num != 0)
        {
            if (num % 4 != 0)
                return false;
            if (num / 4 == 1)
                return true;      
            
            num = num / 4;
        }
        
        return check;
    }
};