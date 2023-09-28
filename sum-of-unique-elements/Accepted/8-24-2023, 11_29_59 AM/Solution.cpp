// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int sum = 0;
        sort(nums.begin(), nums.end());
        bool dup = false;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (dup)
                    dup = false;
                else 
                    sum += nums[i - 1];
                if (i == nums.size() - 1)
                    sum += nums[i];
            }
            else
                dup = true;
        }

        return sum;
    }
};