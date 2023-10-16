class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        auto target_idx = 0;        // keep track of the target idx

        for (auto i = 1; i <= n && target_idx < size(target); i++) {
            if (target.at(target_idx) == i) {
                res.push_back("Push");
                target_idx++;
                continue;
            }

            res.push_back("Push");
            res.push_back("Pop");
        }
        return res;
    }
};