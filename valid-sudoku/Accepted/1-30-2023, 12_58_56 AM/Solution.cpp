// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const char empty_c = '.';
        for (auto i = 0; i < 9; i++) {
            for (auto j = 0; j < 9; j++) {
                if (board[i][j] != empty_c && isSafe(board, i, j, board[i][j]) == false)
                    return false;
            }
        }
        return true;
    }


    bool isSafe(vector<vector<char>>& board, int row, int col, const char num) {

        int count = 0;
        for (int x = 0; x < 9; x++)
            if (board[row][x] == num)
                count++;
        if (count > 1) {
            return false;
        }

        count = 0;
        for (int x = 0; x < 9; x++)
            if (board[x][col] == num)
                count++;
         if (count > 1) {
            return false;
        }
        
        count = 0;
        int startRow = row - row % 3,
            startCol = col - col % 3;
        for (auto i = 0; i < 3; i++)
            for (auto j = 0; j < 3; j++)
                if (board[i + startRow][j + startCol] == num)
                    count++;
         if (count > 1) {
            return false;
        }
        return true;
    }
};