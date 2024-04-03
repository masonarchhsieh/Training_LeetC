class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[0].size(); j++)
                if (board[i][j] == word[0])
                    if (matching(board, word, i, j, 0))
                        return true;
        
        return false;
    }
    
    //prev_move: 0:move left, 1:move right, 2:move up, 3:move down
    bool matching(vector<vector<char>>& board, string word, int x, int y, int idx) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;
        if (word[idx] != board[x][y] || board[x][y] == '$')
            return false;
        //word[idx] == board[x][y]
        if (idx == word.length() - 1)
            return true;
        char c = board[x][y];
        board[x][y] = '$';
        
        bool res = false;
        res |= matching(board, word, x - 1, y, idx + 1);
        res |= matching(board, word, x, y - 1, idx + 1);
        res |= matching(board, word, x + 1, y, idx + 1);
        res |= matching(board, word, x, y + 1, idx + 1);
        board[x][y] = c;
        return res;
    }
};