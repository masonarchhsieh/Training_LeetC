// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even_pos = 0, odd_pos = 0;
        for (auto i = 0; i < position.size(); i++) {
            if (position[i] % 2 == 0)
                even_pos++;
            else
                odd_pos++;
        }

        return min(even_pos, odd_pos);
    }
};