// https://leetcode.com/problems/spiral-matrix

# define RIGHT 0
# define DOWN 1
# define LEFT 2
# define UP 3
# define DIRECTION 4

class Solution {
    bool paths[100][100] = {false};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int x = 0, y = 0, dir = RIGHT;

        while (nextMove(matrix, res, x, y, dir)) {
            ;
        }   

        
        return res;
    }

    bool nextMove(vector<vector<int>>& matrix, vector<int>& res, int &x, int &y, int &dir) {
        if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size())
            return false;
        if (paths[x][y])
            return false;
        res.push_back(matrix[x][y]);
        paths[x][y] = true;
        switch (dir) {
            case RIGHT:
                if (y == matrix[0].size() - 1 || paths[x][y + 1]) {
                    dir = DOWN;
                    x++;
                    break;
                }
                y++;
            break;
            case DOWN:
                if (x == matrix.size() - 1 || paths[x + 1][y]) {
                    dir = LEFT;
                    y--;
                    break;
                }
                x++;
            break;
            case LEFT:
                if (y == 0 || paths[x][y - 1]) {
                    dir = UP;
                    x--;
                    break;
                }
                y--;
            break;
            case UP:
            default:
                if (x == 0 || paths[x - 1][y]) {
                    dir = RIGHT;
                    y++;
                    break;
                }
                x--;
            break;
        }
        return true;
    }
};  