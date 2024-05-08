class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res;
        res.resize(score.size());
        unordered_map<int, int> m;

        for (auto i = 0; i < score.size(); i++)
            m[score[i]] = i;

        sort(score.begin(), score.end());
        for (auto i = 0; i < score.size(); i++) {
            if (i == score.size() - 1)
                res[m[score[i]]] = "Gold Medal";
            else if (i == score.size() - 2)
                res[m[score[i]]] = "Silver Medal";
            else if (i == score.size() - 3)
                res[m[score[i]]] = "Bronze Medal";
            else
                res[m[score[i]]] = to_string(score.size() - i);
        }

        return res;
    }
};