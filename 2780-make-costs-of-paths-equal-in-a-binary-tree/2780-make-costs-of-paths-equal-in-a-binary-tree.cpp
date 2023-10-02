class Solution {
    int res = 0;
public:
    int minIncrements(int n, vector<int>& cost) {
        res = 0;
        int t = balance(cost, 1);
        return res;
    }

    int balance(vector<int>& cost, int idx) {
        if (idx > cost.size())
            return 0;
        int x = balance(cost, idx * 2);
        int y = balance(cost, idx * 2 + 1);
        res += abs(x - y);
        return max(x, y) + cost[idx - 1];

    }
};