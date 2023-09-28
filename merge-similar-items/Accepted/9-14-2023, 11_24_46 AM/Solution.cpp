// https://leetcode.com/problems/merge-similar-items

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1.front() < v2.front();
}
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> res;

        for (auto i : items1)
            res.push_back(i);
        
        for (auto i : items2) {
            bool found = false;
            for (auto &j : res) {
                if (j.front() == i.front()) {
                    j[1] += i.back();
                    found = true;
                    break;
                }
            }
            if (!found)
                res.push_back(i);
        }
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};