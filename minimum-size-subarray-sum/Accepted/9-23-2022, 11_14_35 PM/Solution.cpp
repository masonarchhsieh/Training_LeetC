// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int minCount = INT_MAX;
        int subArrayCount = 0;
        
        while (right < nums.size()) {
            sum += nums[right];
            subArrayCount++;
            right++;
            
            while (sum >= target) {
                minCount = min(minCount, subArrayCount);
                subArrayCount--;
                sum -= nums[left];
                left++;
            }
        }
        
        
        return (minCount == INT_MAX)? 0 : minCount;
    }
};