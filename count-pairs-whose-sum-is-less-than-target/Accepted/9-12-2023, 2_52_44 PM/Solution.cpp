// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int cnt = 0;

        for (auto i = 0; i < nums.size(); i++) {
            for (auto j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target)
                    cnt++;
            }
        }

        return cnt;
    }
};