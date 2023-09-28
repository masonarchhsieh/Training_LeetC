// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        
        while (x > 0 || y > 0) {
            if ((x & 0x01) != (y & 0x01))
                res++;
                
            
            x = (x >> 1);
            y = (y >> 1);
        }
        
        
        return res;
        
    }
};