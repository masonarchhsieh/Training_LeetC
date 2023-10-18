class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        sort(begin(nums), end(nums));
        for (auto i : nums)
            target |= i;
        int res = 0;
        backtrack(nums, 0, 0, target, res);
        return res;
    }

    void backtrack(vector<int>& nums, int index, int value, int target, int& res) {
        if (index == size(nums) || value > target)
            return;

        if ((value | nums.at(index)) == target)
            res++;   
        backtrack(nums, index + 1, (value | nums.at(index)), target, res);
        backtrack(nums, index + 1, value, target, res);
    }
};