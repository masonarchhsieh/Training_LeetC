class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = (nums.size() > 0);
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));

        int _res = 1;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] != 1) {
                _res = 1;
            } else {
                _res++;
                res = max(res, _res);
            }
        }

        return res;
    }
};