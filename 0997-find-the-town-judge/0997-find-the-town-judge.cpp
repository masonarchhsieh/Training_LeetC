class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> v(n + 1, {0, 0});
        for (auto i : trust) {
            v[i.back()].first++;
            v[i.front()].second++;
        }
        for (auto i = 1; i <= n; i++) {
            if (v[i].first == n - 1 && v[i].second == 0)
                return i;
        }
        return -1;
    }
};