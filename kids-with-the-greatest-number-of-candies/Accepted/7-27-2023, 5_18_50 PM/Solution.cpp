// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int max_candies = 0;
        for (auto i : candies)
            max_candies =  max(i, max_candies);

        for (auto i : candies) {
            res.push_back(i + extraCandies >= max_candies);
        }

        return res;
    }
};