// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        const string white_spaces(" \t\f\v\n\r");
        size_t last_cend = s.find_last_not_of(white_spaces);
        size_t last_cbegin = s.find_last_of(white_spaces, last_cend);

        return (last_cend - last_cbegin);
    }
};