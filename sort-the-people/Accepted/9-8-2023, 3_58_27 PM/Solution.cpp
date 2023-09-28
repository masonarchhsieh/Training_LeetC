// https://leetcode.com/problems/sort-the-people

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for (auto i = 0; i < heights.size(); i++) {
            for (auto j = i; j < heights.size(); j++) {
                if (heights[i] < heights[j]) {
                    swap(heights[i], heights[j]);
                    swap(names[i], names[j]);
                }    
            }
        }
        return names;        
    }
};