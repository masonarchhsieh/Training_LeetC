// https://leetcode.com/problems/number-of-valid-clock-times

class Solution {
public:
    int countTime(string time) {
        int cnt = 1;
        // minutes
        if (time[4] == '?' && time[3] == '?')
            cnt *= 60;
        else if (time[3] == '?')
            cnt *= 6;
        else if (time[4] == '?')
            cnt *= 10;

        // hours
        if (time[0] != '?' && time[1] != '?')
            cnt *= 1;
        else if (time[0] == '?' && time[1] == '?')
            cnt *= 24;
        else if ((time[0] == '0'||time[0] =='1') && time[1] == '?')
            cnt *= 10;
        else if (time[0] == '2' && time[1] == '?')
            cnt *= 4;
        else if (time[0] == '?' && time[1] - '0' >= 4)
            cnt *= 2;
        else
            cnt *= 3;

        return cnt;
    }
};