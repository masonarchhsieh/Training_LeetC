class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (board[i][j] == 'X' && !visited[i][j]) {
                    helper(board, visited, i, j, -1);
                    cnt++;
                }

        return cnt;
    }

    void helper(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int mode) {
        if (i < 0 || i >= board.size())
            return;
        if (j < 0 || j >= board[i].size())
            return;
        if (board[i][j] != 'X')
            return;
        if (visited[i][j])
            return;
        visited[i][j] = true;
        // horizontal
        if (mode == -1 || mode == 0)
            helper(board, visited, i - 1, j, 0);
        if (mode == -1 || mode == 1)
            helper(board, visited, i + 1, j, 1);
        if (mode == -1 || mode == 2)
            helper(board, visited, i, j - 1, 2);
        if (mode == -1 || mode == 3)
            helper(board, visited, i, j + 1, 3);
    }
};