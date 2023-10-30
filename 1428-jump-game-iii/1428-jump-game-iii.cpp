class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(size(arr), false);
        bool res = false;
        bfs(arr, visited, start, res);
        return res;
    }

    void bfs(vector<int>& arr, vector<bool>& visited, int i, bool &res) {
        if (i >= size(arr) || i < 0)
            return;
        if (visited[i])
            return;
        
        visited[i] = true;
        if (arr.at(i) == 0) {
            res = true;
            return;
        }
        bfs(arr, visited, i + arr.at(i), res);
        bfs(arr, visited, i - arr.at(i), res);
    }
    
};