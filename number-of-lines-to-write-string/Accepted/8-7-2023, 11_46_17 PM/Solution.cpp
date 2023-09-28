// https://leetcode.com/problems/number-of-lines-to-write-string

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int total_lines = (s.length() > 1), width_of_last_line = 0;
        int count_tmp = 0;

        for (auto i = 0; i < s.length(); i++) {
            if (count_tmp + widths[s[i] - 'a'] == 100 && i == s.length() - 1) {
                width_of_last_line = 100;
                count_tmp = 0;
            }
            else if (count_tmp + widths[s[i] - 'a'] == 100) {
                count_tmp = 0;
                width_of_last_line = 0;
                total_lines++;
            } else if (count_tmp +  widths[s[i] - 'a'] > 100) {
                count_tmp = widths[s[i] - 'a'];
                total_lines++;
                width_of_last_line = count_tmp;
            } else {
                count_tmp += widths[s[i] - 'a'];
                width_of_last_line = count_tmp;
            }
        }
        return { total_lines, width_of_last_line };
    }
};