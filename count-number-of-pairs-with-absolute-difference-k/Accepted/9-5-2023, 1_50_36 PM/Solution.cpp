// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt = 0;
        for (auto i = 0; i < nums.size(); i++) {
            for (auto j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k)
                    cnt++;
            }
        }
        return cnt;
    }
};