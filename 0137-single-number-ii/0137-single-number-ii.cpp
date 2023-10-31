class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (size(nums) < 3)
            return nums.front();

        sort(begin(nums), end(nums));
        if (nums[0] != nums[1])
            return nums[0];
        for (auto i = 1; i < size(nums) - 1; i+=3) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
                continue;
            return (nums[i] == nums[i - 1])? nums[i + 1] : nums[i - 1];
        }
        
        return nums.back();
    }
};