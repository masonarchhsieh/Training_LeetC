// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto i : stones)
            pq.push(i);
        
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            pq.push(abs(x-y));
        }
        return (pq.empty())? 0 : pq.top();
    }
};