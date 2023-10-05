class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int> one_pos;
        const int MODULE = 1000000007;
        for (auto i = 0; i < nums.size(); i++)
            if (nums.at(i) == 1)
                one_pos.push_back(i);
        if (one_pos.size() < 2)
            return one_pos.size();
        long long res = 1;
        for (auto i = 1; i < one_pos.size(); i++) {
            res *= (long long) (one_pos.at(i) - one_pos.at(i - 1));
            res = res % MODULE;
        }

        return res;
    }
};