class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res = 0;
        sort(begin(nums), end(nums));

        for (auto i = 0; i < size(nums) / 2; i++) {
            res = max(res, nums.at(i) + nums.at(size(nums) - 1 - i));
        }
        return res;
    }
};