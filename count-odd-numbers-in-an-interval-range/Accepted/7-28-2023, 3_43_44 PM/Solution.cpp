// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low - (low % 2) ^ (high % 2)) / 2 + (low % 2) + (high % 2);
    }
};