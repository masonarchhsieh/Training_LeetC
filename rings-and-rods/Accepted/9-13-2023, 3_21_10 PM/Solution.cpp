// https://leetcode.com/problems/rings-and-rods

#define NUM_OF_RODS 10
class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> rods;
        for (auto i = 0; i < NUM_OF_RODS; i++) {
            rods.push_back({0, 0, 0});
        }

        for (size_t i = 0; i < rings.length(); i+=2) {
            if (rings[i] == 'R')
                rods[rings[i+1] - '0'][0]++;
            else if (rings[i] == 'G')
                rods[rings[i+1] - '0'][1]++;
            else if (rings[i] == 'B')
                rods[rings[i+1] - '0'][2]++;
            else
                assert(1);
        }

        int cnt = 0;
        for (auto i : rods) {
            if (i[0] > 0 && i[1] > 0 && i[2] > 0)
                cnt++;
        }

        return cnt;
    }
};