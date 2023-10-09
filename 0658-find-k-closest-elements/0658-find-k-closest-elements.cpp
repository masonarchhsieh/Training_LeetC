class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;

        for (auto i = 0; i < size(arr); i++) {
            pq.push({abs(arr.at(i) - x), arr.at(i)});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};