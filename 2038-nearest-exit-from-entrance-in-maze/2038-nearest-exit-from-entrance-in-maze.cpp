class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = size(maze), m = size(maze[0]);

        vector<pair<int, int>> dir = {
            { -1,  0 },
            {  0,  1 },
            {  1,  0 },
            {  0, -1 }
        };

        queue<pair<int, int>> q;
        q.push({ entrance.front(), entrance.back() }); 

        int level = 0;
        // mark the entrance as visited
        maze[entrance.front()][entrance.back()] = '+';

        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto cur = q.front();
                q.pop();

                int i = cur.first, j = cur.second;
                if (!(i == entrance.front() && j == entrance.back()) && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                    return level;
                for (int k = 0; k < dir.size(); k++) {
                    int x = i + dir.at(k).first;
                    int y = j + dir.at(k).second;
                    if (x >= 0 && y < m && y >= 0 && x < n && maze[x][y] != '+') {
                        maze[x][y] = '+';
                        q.push({x, y});
                    }
                }
            }
            level++;
        }

        return -1;
    }
};