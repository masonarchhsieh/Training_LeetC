// https://leetcode.com/problems/take-gifts-from-the-richest-pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        if (k == 0)
            return accumulate(gifts.begin(), gifts.end(), (long long)0);

        sort(gifts.begin(), gifts.end());
        gifts[gifts.size() - 1] = sqrt(gifts.back());

        return pickGifts(gifts, k - 1);
    }
};