class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = size(potions);
        vector<int> res;
        sort(begin(potions), end(potions));

        for (auto &i : spells) {
            int pos = lower_bound(begin(potions), end(potions), ceil((double) success / i)) - begin(potions); 
            res.push_back(n - pos);
        }

        return res;
    }
};