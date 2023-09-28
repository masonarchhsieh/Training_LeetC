// https://leetcode.com/problems/number-of-arithmetic-triplets

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0;

        for (auto i = 0; i < nums.size() - 2; i++) {
            for (auto j = i + 1; j < nums.size() - 1; j++) {
                for (auto k = j + 1; k < nums.size(); k++) {
                    if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};