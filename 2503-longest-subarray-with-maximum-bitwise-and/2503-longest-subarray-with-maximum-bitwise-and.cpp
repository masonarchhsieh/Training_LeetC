class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target = *max_element(nums.begin(), nums.end());

        int res = 1, sub_len = 0;
        for (auto i = 0; i < size(nums); i++) {
            if (nums[i] != target)
                sub_len = 0;
            else
                sub_len++;

            res = max(res, sub_len);
        }

        return res;
    }
};