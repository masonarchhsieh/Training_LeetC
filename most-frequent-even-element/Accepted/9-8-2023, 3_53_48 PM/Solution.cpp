// https://leetcode.com/problems/most-frequent-even-element

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int res = -1, freq = 0;
        sort(nums.begin(), nums.end());
        if (nums[0] % 2 == 0) {
            res = nums[0];
            freq = count(nums.begin(), nums.end(), nums[0]);
        }

        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] % 2 == 0) {
                    if (count(nums.begin(), nums.end(), nums[i]) > freq) {
                        freq = count(nums.begin(), nums.end(), nums[i]);
                        res = nums[i];
                    }
                }
            }
        }

        
        return res;
    }
};