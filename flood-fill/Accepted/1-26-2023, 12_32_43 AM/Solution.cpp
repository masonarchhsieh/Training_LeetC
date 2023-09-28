// https://leetcode.com/problems/flood-fill

class Solution {
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color = image[sr][sc];
        if (old_color != color)
            dfs(image, sr, sc, old_color, color);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int color, int new_color) {
        if (image[r][c] == color) {
            image[r][c] = new_color;
            if (r >= 1)
                dfs(image, r - 1, c, color, new_color);
            if (c >= 1)
                dfs(image, r, c - 1, color, new_color);
            if (r + 1 < image.size())
                dfs(image, r + 1, c, color, new_color);
            if (c + 1 < image[0].size())
                dfs(image, r, c + 1, color, new_color);
        }
    }
};