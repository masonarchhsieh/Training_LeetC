class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        for (auto i = 0; i < size(neededTime); i++) {
            auto j = i + 1;
            for (j = i + 1; j < size(neededTime); j++) {
                if (colors.at(j) != colors.at(i)) {
                    res += (accumulate(begin(neededTime) + i, begin(neededTime) + j, 0) - *max_element(begin(neededTime) + i, begin(neededTime) + j));
                    
                    i = j - 1;
                    break;
                }
                // same color
                if (j == size(neededTime) - 1) {
                    res += (accumulate(neededTime.begin() + i, neededTime.end(), 0) - 
                            *max_element(neededTime.begin() + i, neededTime.end()));
                    i = j;
                    break;
                }
            }
        }
        
        return res;
    }
};