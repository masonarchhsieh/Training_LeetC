class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int cur = res;

        for (auto i = 0; i < k; i++) {
            cur -= cardPoints[k - 1 - i];
            cur += cardPoints[cardPoints.size() - 1 - i];
            res = max(res, cur);
        }
        return res;
    }
};