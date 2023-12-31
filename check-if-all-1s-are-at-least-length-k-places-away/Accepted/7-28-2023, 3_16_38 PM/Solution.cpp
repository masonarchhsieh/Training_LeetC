// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int left_i = -1;

        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                if (i - left_i - 1 < k && left_i != -1)
                    return false;
                else
                    left_i = i;
        }

        return true;
    }
};