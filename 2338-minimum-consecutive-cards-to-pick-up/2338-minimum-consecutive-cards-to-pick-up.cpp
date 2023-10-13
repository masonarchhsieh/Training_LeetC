class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = INT_MAX;
        unordered_map<int, vector<int>> card_pos;
        for (auto i = 0; i < size(cards); i++)
            card_pos[cards[i]].push_back(i);

        for (auto i : card_pos) {
            for (auto j = 1; j < size(i.second); j++)
                res = min(res, i.second[j] - i.second[j - 1] + 1);
        }

        return (res == INT_MAX)? -1 : res;
    }
};