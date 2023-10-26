class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int l = 0, r = size(costs) - 1;
        for (;l < candidates; l++)
            pq.push({costs[l], l});
        l = candidates - 1;
        for (int i = size(costs) - 1; 
                i > l && (size(costs) - 1 - i) < candidates; i--) {
            pq.push({costs[i], i});
            r = i;
        }
        
        while (k > 0) {
            res += (long long) pq.top().first;
            k--;
            int idx = pq.top().second;
            pq.pop();

            if (l + 1 >= r)
                continue;
            if (idx <= l) {
                l++;
                pq.push({costs[l], l});
            } else {
                r--;
                pq.push({costs[r], r});
            }
        }

        return res;
    }
};