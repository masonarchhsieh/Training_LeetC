// https://leetcode.com/problems/count-special-quadruplets

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int cnt = 0;
        for (auto i = 0; i < nums.size() - 3; i++) {
            for (auto j = i + 1; j < nums.size() - 2; j++) {
                for (auto k = j + 1; k < nums.size() - 1; k++) {
                    cnt += count(nums.begin() + k, nums.end(), nums[i] + nums[j] + nums[k]);
                }
            }
        }

        return cnt;
    }
};