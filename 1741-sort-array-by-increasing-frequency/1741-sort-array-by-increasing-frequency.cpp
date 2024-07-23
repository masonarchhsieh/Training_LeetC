struct Compare {
    bool operator()(const pair<int, int> &T1, const pair<int, int> &T2) {
        if (T1.second == T2.second)
            return T1.first < T2.first;
        return T1.second >= T2.second;
    }
};
class Solution {

public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto i : nums)
            m[i]++;

        priority_queue<pair<int, int>, vector<pair<int,int>>, Compare> pq;
        for (auto i : m) {
            pq.push({i.first, i.second});
        }

        while (!pq.empty()) {
            for (auto i = 0; i < pq.top().second; i++) {
                res.push_back(pq.top().first);
            }
            pq.pop();
        }
        return res;
    }
};