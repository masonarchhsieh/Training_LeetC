class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = size(dist), res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto i = 0; i < n; i++)
            pq.push((dist.at(i) + speed.at(i) - 1) / speed.at(i));
        
        while (!pq.empty() && res < pq.top()) {
            res++;
            pq.pop();
        }
        return res;
    }
};