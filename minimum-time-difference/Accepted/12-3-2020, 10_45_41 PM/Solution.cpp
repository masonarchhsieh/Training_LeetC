// https://leetcode.com/problems/minimum-time-difference

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        
        for (int i=0; i<timePoints.size(); i++) {
       
            int t1 = stoi(timePoints[i].substr(0,2)) * 60 + stoi(timePoints[i].substr(3,2));
                       
            for (int j=i+1; j<timePoints.size(); j++) {
                if (timePoints[i] == timePoints[j])
                    return 0;
                    
                // "HH:MM"
                int t2 = stoi(timePoints[j].substr(0,2)) * 60 + stoi(timePoints[j].substr(3,2));              
                
                int temp1, temp2;
                if (t1 >= t2) {
                    temp1 = t1 - t2;
                    temp2 = (t2 + 60 * 24) - t1;
                }
                else {
                    temp1 = t2 - t1;
                    temp2 = (t1 + 60 * 24) - t2;
                }
                res = min(res, min(temp1, temp2)); 
            }
        }

        return res;
    }
};