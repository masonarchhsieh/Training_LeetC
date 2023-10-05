class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int odd_nums_in_window = 0;
        int j = 0, num_subarrays = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums.at(i) % 2 == 1) {
                odd_nums_in_window++;
                num_subarrays = 0;
            }
            while (odd_nums_in_window == k) {
                num_subarrays++;
                if (nums.at(j++) % 2 == 1)
                    odd_nums_in_window--;
            }
            res += num_subarrays;
        }
        return res;
    }
};