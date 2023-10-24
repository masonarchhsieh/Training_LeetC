class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int moves = 0;
        for (auto i = 1; i < size(nums); i++) {
            moves += nums.at(i) - nums.front();
        }

        return moves;
    }
};