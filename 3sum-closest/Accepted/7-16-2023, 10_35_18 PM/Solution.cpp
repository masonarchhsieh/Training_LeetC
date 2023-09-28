// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int nearest_sum = nums[0] + nums[1] + nums[2];

        for (auto i = 0; i < nums.size(); i++) {
            auto start = i + 1;
            auto end = nums.size() - 1;

            while (start < end) {
                int cur_sum = nums[start] + nums[end] + nums[i];
                if (abs(cur_sum - target) < abs(nearest_sum - target))
                    nearest_sum = cur_sum;
                if (cur_sum < target)
                    start++;
                else
                    end--;
            }
        }

        return nearest_sum;
    }
};