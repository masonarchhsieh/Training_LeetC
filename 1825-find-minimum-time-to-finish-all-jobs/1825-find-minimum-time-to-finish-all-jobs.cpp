class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(begin(jobs), end(jobs));
        vector<int> dis(k, 0);
        int res = INT_MAX;
        backtrack(jobs, dis, k, 0, res);
        return res;
    }

    void backtrack(vector<int>& jobs, vector<int>& dis, int k, int index, int& res) {
        if (index == size(jobs)) {
            int _max = 0;
            for (auto i : dis)
                _max = max(_max, i);
            res = min(res, _max);
            return;
        }

        if (*max_element(begin(dis), end(dis)) >= res)
            return;
        
        for (auto i = 0; i < k; i++) {
            dis[i] += jobs.at(index);
            backtrack(jobs, dis, k, index + 1, res);
            dis[i] -= jobs.at(index);

            if (dis.at(i) == 0)
                return;
        }
    }
};