class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++){
            if (nums[n-1-i] < i && i <= nums[n-i]){
                return i;
            }
        }
        if (n <= nums[0]) 
            return n;
        return -1;
    }
};