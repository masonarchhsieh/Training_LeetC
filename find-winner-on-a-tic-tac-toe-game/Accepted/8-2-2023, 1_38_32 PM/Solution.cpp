// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
    int dp[3][3] = { 0 };
public:
    string tictactoe(vector<vector<int>>& moves) {
        for (auto i = 0; i < moves.size(); i++) {
            dp[moves[i][0]][moves[i][1]] = (i % 2) + 1;
        }
        if (helper(1))
            return "A";
        else if (helper(2))
            return "B";
        for (auto i = 0; i < 3; i++)
            for (auto j = 0; j < 3; j++)
                if (dp[i][j] == 0)
                    return "Pending";
        return "Draw";
    }

    bool helper(int player) {
        if (dp[0][0] == player && dp[1][0] == player && dp[2][0] == player)
            return true;
        if (dp[0][1] == player && dp[1][1] == player && dp[2][1] == player)
            return true;
        if (dp[0][2] == player && dp[1][2] == player && dp[2][2] == player)
            return true;

        if (dp[0][0] == player && dp[0][1] == player && dp[0][2] == player)
            return true;
        if (dp[1][0] == player && dp[1][1] == player && dp[1][2] == player)
            return true;
        if (dp[2][0] == player && dp[2][1] == player && dp[2][2] == player)
            return true;

        if (dp[0][0] == player && dp[1][1] == player && dp[2][2] == player)
            return true;
        if (dp[0][2] == player && dp[1][1] == player && dp[2][0] == player)
            return true;
        return false;
    };
};