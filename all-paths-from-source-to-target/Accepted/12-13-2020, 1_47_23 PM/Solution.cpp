// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        int m = graph.size();
        
        if (m == 0) 
            return res;
        dfs(graph, res, path, 0, m-1);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> path, int src, int dst) {
        path.push_back(src);
        if (src == dst) {
            res.push_back(path);
            return;
        }
        
        for (auto node : graph[src]) 
            dfs(graph, res, path, node, dst);
        
    }
    
    
};