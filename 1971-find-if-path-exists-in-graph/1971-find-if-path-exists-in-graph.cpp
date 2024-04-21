
class Solution {
    vector<int> travelled;
    vector<vector<int>> matrix;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        matrix = vector<vector<int>>(n, vector<int>());
        travelled = vector<int>(n, 0);

        for (auto &i : edges) {
            matrix[i.front()].push_back(i.back());
            matrix[i.back()].push_back(i.front());
        }

        dfs(source);
        return !(travelled[destination] == 0);
    }

    void dfs(int source) {
        travelled[source] = 1;
        for (auto &i : matrix[source]) {
            if (travelled[i] == 0)
                dfs(i);
        }
    }

};