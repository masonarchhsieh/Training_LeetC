class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        for (auto i = 0; i < neededTime.size(); i++) {
            auto j = i + 1;
            for (j = i + 1; j < neededTime.size(); j++) {
                if (colors[j] != colors[i]) {
                    res += (accumulate(neededTime.begin() + i, neededTime.begin() + j, 0) - 
                            *max_element(neededTime.begin() + i, neededTime.begin() + j));
                    i = j - 1;
                    break;
                }
                // same color
                if (j == neededTime.size() - 1) {
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