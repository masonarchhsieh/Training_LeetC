// https://leetcode.com/problems/distribute-candies-to-people

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int n = 1;
        while (candies > 0) {
            if (candies / n)
                res[(n - 1) % num_people] += n;
            else
                res[(n - 1) % num_people] += candies;
            candies -= n;
            n++;
        }
        return res;
    }
};