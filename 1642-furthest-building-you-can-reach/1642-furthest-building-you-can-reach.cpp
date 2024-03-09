class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;

        for (auto i = 0; i < size(heights) - 1; i++) {
            int diff = heights.at(i + 1) - heights.at(i);

            if (diff > 0)
                pq.push(-diff);
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }

            if (bricks < 0)
                return i;
        }

        return size(heights) - 1;
    }
};