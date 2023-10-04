class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() > h)
            return -1;
        int res = *max_element(piles.begin(), piles.end());
        int r = res, l = 1, mid;

        while (l <= r) {
            mid = (l + r) / 2;
            if (solve(piles, mid) <= h) {
                res = min(res, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    }

    long long solve(vector<int>& piles, int speed) {
        long long n = 0;
        for (auto i : piles)
            n += ceil(i / (double)speed);
        return n;
    }
};