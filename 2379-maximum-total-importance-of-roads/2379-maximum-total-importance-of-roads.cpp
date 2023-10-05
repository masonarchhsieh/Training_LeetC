    bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.second < p2.second)
            return true;
        return false;
    }
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> v;
        for (auto i = 0; i < n; i++)
            v.push_back(make_pair(i, 0));

        for (auto i = 0; i < roads.size(); i++) {
            v[roads[i][0]].second++;
            v[roads[i][1]].second++;
        }
        sort(v.begin(), v.end(), compare);
        long long res = 0;
        long long importance = 1;

        for (auto i : v) {
            res += importance * i.second;
            importance++;
        }
        return res;
    }
};