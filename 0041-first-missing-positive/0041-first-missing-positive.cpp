class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : nums) {
            if (i > 0)
                pq.push(i);
        }

        int i = 1;
        while (!pq.empty() && i == pq.top()) {
            for (;!pq.empty() && i == pq.top(); pq.pop()) {
                ;
            }
            i++;
        }

        return i;
    }
};