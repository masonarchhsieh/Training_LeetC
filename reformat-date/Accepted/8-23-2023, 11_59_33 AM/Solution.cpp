// https://leetcode.com/problems/reformat-date

class Solution {
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string days[31] = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th",
    "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th", "21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31st"};
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string day, month, year;
        
        ss >> day >> month >> year;
        auto d = find(days, days+31, day);
        auto m = find(months, months+12, month);
        month = to_string((m - months)+ 1);
        if ((m - months)+ 1 < 10)
            month = "0" + month;
        day = to_string((d - days)+ 1);
        if ((d - days) + 1 < 10)
            day = "0" + day;
        
        return year + "-" + month + "-" + day;
    }
};