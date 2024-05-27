class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));

        for (auto i = 1; i < nums.size(); i++) {
            if (nums[nums.size() - 1 - i] < i && i <= nums[nums.size() - i])
                return i;
        }

        return (nums.size() <= nums[0])? nums.size() : -1;
    }
};