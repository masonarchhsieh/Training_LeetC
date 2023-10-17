class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1 ) && board[i][j] == 'O')
                    dfs(board, visited, i, j);
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }

    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != 'O')
            return;
        if (visited[i][j])
            return;
        if (board[i][j] == 'O')
            board[i][j] = '#';
        visited[i][j] = true;
        dfs(board, visited, i - 1, j);
        dfs(board, visited, i + 1, j);
        dfs(board, visited, i, j - 1);
        dfs(board, visited, i, j + 1);
    }
};