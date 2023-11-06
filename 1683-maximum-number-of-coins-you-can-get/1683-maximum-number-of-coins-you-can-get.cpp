class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles), end(piles));
        int l = 0, r = size(piles) - 2;
        int res = 0;

        while (l < r) {
            res += piles.at(r);
            r -= 2;
            l++;
        }

        return res;
    }
};