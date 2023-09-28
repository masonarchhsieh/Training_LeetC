// https://leetcode.com/problems/determine-the-winner-of-a-bowling-game

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = calculateScore(player1), score2 = calculateScore(player2);
        
        if (score1 == score2)
            return 0;

        return (score1 > score2)? 1 : 2;
    }

    int calculateScore(vector<int>& p) {
        int res = 0;
        for (auto i = 0; i < p.size(); i++) {
            if (i >= 1 && p[i - 1] == 10)
                res += 2 * p[i];
            else if (i >= 2 && p[i - 2] == 10)
                res += 2 * p[i];
            else
                res += p[i];
        }
        return res;
    }
};