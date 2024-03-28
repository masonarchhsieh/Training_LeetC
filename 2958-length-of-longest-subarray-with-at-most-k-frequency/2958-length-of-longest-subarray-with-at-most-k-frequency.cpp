class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len = 0;
        unordered_map<int, int> m;
        
        for (auto l = 0, r = 0; r < size(nums); r++) {
            m[nums[r]]++;
            if (m[nums[r]] > k) {
                while (nums[l] != nums[r])  {
                    m[nums[l++]]--;
                }
                m[nums[l++]]--;
            }
            len = max(len, r - l + 1);
        }

        return len;
    }
};