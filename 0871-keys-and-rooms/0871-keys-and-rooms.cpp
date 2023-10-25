class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> gotKeys(size(rooms), false);
        dfs(rooms, gotKeys, 0);

        return count(begin(gotKeys), end(gotKeys), true) == size(gotKeys);
    }

    void dfs(vector<vector<int>>& rooms, vector<bool>& gotKeys, int door) {
        gotKeys[door] = true;

        for (auto i = 0; i < size(rooms[door]); i++) {
            if (!gotKeys[rooms[door][i]])
                dfs(rooms, gotKeys, rooms[door][i]);
        }
    }
};