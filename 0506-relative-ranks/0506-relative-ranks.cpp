class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> v = score;
        sort(v.rbegin(), v.rend());

        vector<string> res(score.size(), "");
        for (auto i = 0; i < size(score); i++) {
            auto place = std::find(v.begin(), v.end(), score[i]) - v.begin();
            switch (place) {
                case 0:
                    res[i] = "Gold Medal";
                    break;
                case 1:
                    res[i] = "Silver Medal";
                    break;
                case 2:
                    res[i] = "Bronze Medal";
                    break;
                default:
                    res[i] = std::to_string(place + 1);
                    break;
            }
        }
        return res;
    }
};