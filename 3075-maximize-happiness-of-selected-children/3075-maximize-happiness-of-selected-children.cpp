class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        sort(happiness.rbegin(), happiness.rend());
        
        for (auto i = 0; i < k; i++) {
            res += max(happiness.at(i) - i, 0);
        }

        return res;
    }
};