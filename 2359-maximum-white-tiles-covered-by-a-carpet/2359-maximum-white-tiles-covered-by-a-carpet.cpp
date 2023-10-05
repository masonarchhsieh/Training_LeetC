class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int res = 0;
        sort(tiles.begin(), tiles.end());

        // carpetLen is the window len
        int num_white_tiles_in_the_window = 0;
        int p = 0;

        for (auto left = 0, right = 0; right < tiles.size() && res < carpetLen; ) {
            if (tiles.at(left).front() + carpetLen > tiles.at(right).back()) {
                num_white_tiles_in_the_window += tiles.at(right).back() - tiles.at(right).front() + 1;
                res = max(res, num_white_tiles_in_the_window);
                // increment right index
                right++;
                continue;
            }
            // otherwise move left index
            p = max(tiles.at(left).front() + carpetLen - tiles.at(right).front(), 0);
            res = max(res, num_white_tiles_in_the_window + p);
            num_white_tiles_in_the_window -= (tiles.at(left).back() - tiles.at(left).front() + 1);
            left++;
        }

        return res;
    }
};