// https://leetcode.com/problems/most-visited-sector-in-a-circular-track

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> pts;
        for (auto i = 0; i < n; i++)
            pts.push_back(0);

        for (auto i = 1; i < rounds.size(); i++) {
            if (i == 1)
                pts[(rounds[i-1] - 1) % n]++;
            for (auto j = 1; j < n; j++) {
                pts[(rounds[i-1] + j - 1) % n]++;
                if (rounds[i] - 1 == (rounds[i-1] + j - 1) % n)
                    break;
            }
        }
        vector<int> res;
        vector<int>::iterator it = max_element(pts.begin(), pts.end());
        res.push_back(it - pts.begin() + 1);
        for (auto i = it + 1; i != pts.end(); i++) {
            if (*i == *it)
                res.push_back(i - pts.begin() + 1);
        }
        return res; 
    }
};