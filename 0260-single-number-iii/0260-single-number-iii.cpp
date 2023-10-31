class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> res;
        if (nums.front() != nums[1])
            res.push_back(nums.front());
        for (auto i = 1; i < size(nums) - 1; i++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                res.push_back(nums[i]);
        }
        if (nums.back() != nums[nums.size() - 2])
            res.push_back(nums.back());
        return res;
    }
};