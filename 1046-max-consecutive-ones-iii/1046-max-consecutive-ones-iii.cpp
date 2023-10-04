class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int count_zero = 0;
        auto i = 0, j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                count_zero++;
            while (count_zero > k) {
                if (nums[j] == 0)
                    count_zero--;
                j++;
            }

            // update the result
            int window_length = i - j + 1;
            res = max(res, window_length);
        }

        
        return res;
    }
};