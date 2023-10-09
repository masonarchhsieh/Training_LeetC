class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;

        for (auto i = 0; i < 31; i++) {
            int num_with_this_bit = 0;
            for (auto j = 0; j < size(nums); j++) {
                if (nums[j] & (1 << i))
                    num_with_this_bit++;
            }
            res += (num_with_this_bit * (size(nums) - num_with_this_bit));
        }

        return res;
    }
};