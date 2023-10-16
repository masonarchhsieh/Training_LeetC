class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> _set;
        int ops = 0;
        for (int i = size(nums) - 1; i >= 0; i--) {
            if (nums.at(i) <= k)
                _set.insert(nums.at(i));
            ops++;
            if (size(_set) == k)
                break;
        }
        return ops;
    }
};