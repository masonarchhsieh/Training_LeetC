class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0;
        int l = 0;
        while (l < nums.size()) {
            if (nums[l] % 2 == 0) {
                int _max = 1;
                if (res == 0 && nums[l] <= threshold)
                    res = 1;
                for (auto r = l + 1; r < nums.size(); r++) {
                    if (nums[r] % 2 != nums[r-1] % 2 && nums[l] <= threshold && nums[r] <= threshold) {
                        _max++;
                        res = max(res, _max);
                        continue;
                    }
                    break;
                }
            }
            l++;
        }


        return res;
    }
};