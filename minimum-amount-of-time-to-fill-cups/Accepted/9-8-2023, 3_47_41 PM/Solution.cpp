// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int fill_times = 0;
        while (true) {
            sort(amount.begin(), amount.end());
            if (amount[2] == 0)
                break;
            amount[2]--;
            amount[1]--;
            fill_times++;
        }
        return fill_times;
    }   
};