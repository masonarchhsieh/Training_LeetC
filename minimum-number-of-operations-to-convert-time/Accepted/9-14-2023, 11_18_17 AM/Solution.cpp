// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time

class Solution {
public:
    int convertTime(string current, string correct) {
        int diff = 0;
        int cnt = 0;
        diff = (current[0] - correct[0]) * 60 * 10;
        diff += (current[1] - correct[1]) * 60;
        diff += (current[3] - correct[3]) * 10;
        diff += (current[4] - correct[4]);
        diff = abs(diff);
        while (diff > 0) {
            if (diff >= 60) {
                diff -= 60;
            } else if (diff >= 15)
                diff -= 15;
            else if (diff >= 5)
                diff -= 5;
            else
                diff -= 1;
            cnt++;
        }
        return cnt;
    }
};