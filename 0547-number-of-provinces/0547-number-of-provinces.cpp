class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = size(isConnected);
        vector<bool> visited(n + 1, false);
        vector<int> adj[n + 1];

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }

        int cnt = 0;
        for (auto i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
    
    
    void dfs(vector<int> adj[], vector<bool>& visited, int start) {
        visited[start] = true;
        
        for (auto &i : adj[start]) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(adj, visited, i);
            }
        }
    }
};