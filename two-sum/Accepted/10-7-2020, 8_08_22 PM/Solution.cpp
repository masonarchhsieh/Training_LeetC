// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            num1 = i;
            bool check = false;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] + nums[i] == target)
                {
                    num2 = j;
                    check = true;
                    break;
                }
            }
          
            if (check)
                break;
        }
        
        vector<int> res;

        res.push_back(num1);
        res.push_back(num2);        
        return res;
    }
};