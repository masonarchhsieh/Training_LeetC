// https://leetcode.com/problems/determine-color-of-a-chessboard-square

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a') % 2) ^ ((coordinates[1] - '1') % 2);
    }
};