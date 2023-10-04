class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        auto i = 0, j = 0;
        
        while (i < nums.size()) {
            if (!nums[i])
                k--;
            if (k < 0) {
                if (!nums[j])
                    k++;
                j++;
            }
            i++;
        }

        
        return i - j;
    }
};