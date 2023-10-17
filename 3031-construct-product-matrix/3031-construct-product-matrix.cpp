class Solution {
    const int MOD = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m, 0));
        
        long long int products = 1;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++) {
                p[i][j] = products;
                products = (products * grid[i][j]) % MOD;
            }
        products = 1;
        for (auto i = n - 1; i >= 0; i--) {
            for (auto j = m - 1; j >= 0; j--) {
                p[i][j] = (p[i][j] * products) % MOD;
                products = (products * grid[i][j]) % MOD;
            }
        }
        
        return p;
    }
};