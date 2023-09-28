// https://leetcode.com/problems/mean-of-array-after-removing-some-elements

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort (arr.begin(), arr.end());
        vector<int> tmp(arr.begin() + arr.size() / 20, arr.end() - arr.size() / 20);
        return accumulate(tmp.begin(), tmp.end(), 0.0) / tmp.size();
    }
};