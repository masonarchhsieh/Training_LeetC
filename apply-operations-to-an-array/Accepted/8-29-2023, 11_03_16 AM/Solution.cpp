// https://leetcode.com/problems/apply-operations-to-an-array

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res;
        int n_zero = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                n_zero++;
            }
            else {
                if ((i != nums.size() - 1) && nums[i] == nums[i + 1]) {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                } 
                res.push_back(nums[i]);
            }
                
        }
        for (auto i = 0; i < n_zero; i++)
            res.push_back(0);

        return res;
    }
};