// https://leetcode.com/problems/find-subarrays-with-equal-sum

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> sum_pairs;

        for (auto i = 1; i < nums.size(); i++) {
            if (sum_pairs.find(nums[i] + nums[i-1]) != sum_pairs.end())
                return true;
            sum_pairs.insert(nums[i] + nums[i-1]);
        }    
        return false;
    }
};