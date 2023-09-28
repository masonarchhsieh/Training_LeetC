// https://leetcode.com/problems/number-of-lines-to-write-string

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int total_lines = (s.length() > 1), width_of_last_line = 0;

        for (auto i = 0; i < s.length(); i++) {
            if (width_of_last_line + widths[s[i] - 'a'] == 100 && i == s.length() - 1) {
                width_of_last_line = 100;
            }
            else if (width_of_last_line + widths[s[i] - 'a'] == 100) {
                width_of_last_line = 0;
                total_lines++;
            } else if (width_of_last_line +  widths[s[i] - 'a'] > 100) {
                width_of_last_line = widths[s[i] - 'a'];
                total_lines++;
            } else {
                width_of_last_line += widths[s[i] - 'a'];
            }
        }
        return { total_lines, width_of_last_line };
    }
};