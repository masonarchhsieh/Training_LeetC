// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i=2; i<cost.size(); i++) {
            cost[i] = cost[i] + min(cost[i-1], cost[i-2]);
        }
        
        return min(cost.at(cost.size()-1), cost.at(cost.size()-2));
    }
};