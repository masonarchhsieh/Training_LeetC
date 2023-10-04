class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                int j = i + 1;
                for (j = i + 1; j < nums.size(); j++) {
                    if (nums[j] == 0)
                        break;
                }
                res = max(res, j - i);
                i = j;
            }
        }
        return res;
    }
};