// https://leetcode.com/problems/day-of-the-year

class Solution {
public:
    int dayOfYear(string date) {
        int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int mon = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int year = stoi(date.substr(0, 4));
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            days[2] = 29;
        return accumulate(days, days + mon, 0) + day;
    }
};