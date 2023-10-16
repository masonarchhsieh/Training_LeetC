class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> collected(k, false);
        int ops = 0;
        for (int i = size(nums) - 1; i >= 0; i--) {
            if (nums.at(i) - 1 < k)
                collected[nums.at(i) - 1] = true;
            ops++;
            if (std::find(collected.begin(), collected.end(), false) == collected.end())
                break;
        }
        return ops;
    }
};