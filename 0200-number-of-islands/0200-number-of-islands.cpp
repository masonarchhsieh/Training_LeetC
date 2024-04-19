class Solution {
  
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m; i++) {
            for (int j=0;j<n; j++) {
                if (grid[i][j] =='1'){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '0';
        
        if (i+1<grid.size() && grid[i+1][j] == '1')
            dfs(grid, i+1, j);
        if (j+1<grid[0].size() && grid[i][j+1] == '1')
            dfs(grid, i, j+1);
        if (i-1>=0 && grid[i-1][j] == '1')
            dfs(grid, i-1, j);
        if (j-1>=0 && grid[i][j-1] == '1')
            dfs(grid, i, j-1);
    }
};