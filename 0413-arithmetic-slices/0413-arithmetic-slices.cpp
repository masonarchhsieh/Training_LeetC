class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        int res = 0;
        int sub_array_len = (nums[2] - nums[1] == nums[1] - nums[0])? 2 : 0;
        for (auto i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] != nums[i - 1] - nums[i - 2]) {
                res += countSequences(sub_array_len);
                sub_array_len = 2;
                continue;
            }
            sub_array_len++;
        }
        res += countSequences(sub_array_len);
        
        return res;
    }

    int countSequences(int len) {
        if (len < 3)
            return 0;
        if (len == 3)
            return 1;
        return (len - 1) * (len - 2) / 2;
    }
};