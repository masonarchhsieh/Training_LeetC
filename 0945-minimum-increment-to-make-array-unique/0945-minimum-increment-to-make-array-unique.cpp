class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves = 0;
        sort(nums.begin(), nums.end());

        for (auto i = 1; i < size(nums); i++) {
            if (nums[i] <= nums[i-1]) {
                moves += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        
        return moves;
    }
};