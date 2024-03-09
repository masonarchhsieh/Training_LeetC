class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        for (auto &it : flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dis(n);
        for (auto &i : dis) {
            i = INT_MAX;
        }
        dis[src] = 0;
        queue<tuple<int, int, int>> pq;
        pq.push({src, 0, 0});

        while (!pq.empty()) {
            int node = get<0>(pq.front());
            int step = get<1>(pq.front());
            int d = get<2>(pq.front());
            pq.pop();

            for (auto &it : adj[node]) {
                int nxt_node = it.first;
                int nxt_d = it.second;

                if (nxt_d + d < dis[nxt_node] && step <= k) {
                    dis[nxt_node] = nxt_d + d;
                    pq.push({nxt_node, step + 1, nxt_d + d});
                }
            }
        }
        return (dis[dst] == INT_MAX)? -1 : dis[dst];
    }
};