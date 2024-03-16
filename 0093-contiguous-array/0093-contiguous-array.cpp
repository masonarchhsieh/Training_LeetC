class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int zeros = 0, ones = 0, maxLen = 0;

        m[0] = -1;
        for (auto i = 0; i < nums.size(); i++) {
            nums[i] == 0? ++zeros : ++ones;
            int diff = zeros - ones;
            
            if (m.count(diff)) {
                maxLen = max(maxLen, i - m[diff]);
                continue;
            } 
            m[diff] = i;
        }

        return maxLen;
    }
};