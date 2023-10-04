class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        auto i = 0;

        while (i < nums.size() && nums.size() - i >= res) {
            bool canDelete = true;
            int n = 0;
            for (auto j = i; j < nums.size(); j++) {
                if (nums[j] == 0) {
                    if (!canDelete)
                        break;
                    canDelete = false;
                    continue;
                }
                n++;
            }
            res = max(res, n - (canDelete));
            i++;
        }


        return res;
    }
};