// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it;
        it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        int idx = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                if (nums[i] != 1)
                    return 1;
                idx = i;
                break;
            }
        }
        for (auto i = idx + 1; i < nums.size(); i++)
            if (nums[i] - nums[i - 1] != 1)
                return nums[i-1] + 1;

        return (nums[nums.size() - 1] > 0)? nums[nums.size() - 1] + 1 : 1;
    }
};