// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = candies[0];
        for (int i=0; i<candies.size(); i++)
            max = (max > candies[i]) ? max : candies[i];
        
        vector<bool> res;
        res.resize(candies.size());
        for (int i=0; i<candies.size(); i++)
            res[i] = (candies[i] + extraCandies >= max)? true : false;
        
        return res;
    }
};