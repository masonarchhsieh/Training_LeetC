// https://leetcode.com/problems/total-distance-traveled

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int dis = 0;

        while (mainTank > 0) {
            if (mainTank >= 5)
                dis += 50;
            else
                dis += (mainTank % 5) * 10;
            mainTank = mainTank - 5;
            if (mainTank >= 0)
                mainTank += (additionalTank-- > 0);
        }


        return dis;
    }
};