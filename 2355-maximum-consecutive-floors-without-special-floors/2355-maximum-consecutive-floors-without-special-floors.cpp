class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int res = 0;
        sort(special.begin(), special.end());

        for (auto i = 1; i < special.size(); i++)
            res = max(res, special[i] - special[i-1] - 1);
        if (bottom != special.front())
            res = max(res, special.front() - bottom);
        if (top != special.back())
            res = max(res, top - special.back());

        return res;
    }
};