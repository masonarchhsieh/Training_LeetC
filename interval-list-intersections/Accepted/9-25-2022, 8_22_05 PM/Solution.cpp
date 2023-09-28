// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        
        for (int f_itr=0, s_itr=0; f_itr<firstList.size() && s_itr<secondList.size();) {
            if (firstList[f_itr][0] <= secondList[s_itr][0]) {
                if (firstList[f_itr][1] >= secondList[s_itr][0])
                    res.push_back({secondList[s_itr][0], min(firstList[f_itr][1], secondList[s_itr][1])});
            } else {
                if (secondList[s_itr][1] >= firstList[f_itr][0])
                    res.push_back({firstList[f_itr][0], min(firstList[f_itr][1], secondList[s_itr][1])});
            }
            
            if (firstList[f_itr][1] <= secondList[s_itr][1]) {
                f_itr++;
            } else {
                s_itr++;
            }  
        }
        
        return res;
    }
};