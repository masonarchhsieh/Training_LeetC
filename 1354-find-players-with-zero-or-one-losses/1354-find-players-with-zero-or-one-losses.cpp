class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {\
        int n_players = 0;
        for (auto i : matches)
            n_players = max(n_players, max(i.front(), i.back()));

        int n = size(matches);
        vector<vector<int>> res(2);
        vector<int> wins(n_players + 1, 0);
        vector<int> loses(n_players + 1, 0);

        for (auto players : matches) {
            wins[players.front()]++;
            loses[players.back()]++;
        }

        for (auto i = 1; i <= n_players; i++) {
            if (wins[i] > 0 && loses[i] == 0)
                res[0].push_back(i);
            if (loses[i] == 1)
                res[1].push_back(i);
        }
        return res;
    }
};