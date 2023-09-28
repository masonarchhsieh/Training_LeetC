// https://leetcode.com/problems/count-special-quadruplets

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int cnt = 0;
        for (auto i = 0; i < nums.size() - 3; i++) {
            for (auto j = i + 1; j < nums.size() - 2; j++) {
                for (auto k = j + 1; k < nums.size() - 1; k++) {
                    for (auto l = k + 1; l < nums.size(); l++)
                        if (nums[i] + nums[j] + nums[k] == nums[l])
                            cnt++;
                }
            }
        }

        return cnt;
    }
};