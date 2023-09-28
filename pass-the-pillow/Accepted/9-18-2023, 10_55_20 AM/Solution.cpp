// https://leetcode.com/problems/pass-the-pillow

class Solution {
public:
    int passThePillow(int n, int time) {
        int itr = 1, dir = 1;

        while (time-- > 0) {
            if (itr == n) {
                dir = -1;
            }
            else if (itr == 1) {
                dir = 1;
            }
            itr += dir * 1;
        }
        return itr;
    }
};