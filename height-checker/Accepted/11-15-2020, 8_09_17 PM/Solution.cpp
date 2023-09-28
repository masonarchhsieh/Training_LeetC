// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy;
        copy.assign(heights.begin(), heights.end());
        sort(copy.begin(), copy.end());
        int res = 0;
        
        for (int i=0; i<heights.size(); i++) {
            if (heights[i] != copy[i])
                res++;
        }
        
        return res;
    }
};