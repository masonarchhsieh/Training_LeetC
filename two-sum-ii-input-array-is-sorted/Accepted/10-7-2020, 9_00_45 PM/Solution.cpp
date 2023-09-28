// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int itr1 = 0, itr2 = numbers.size() - 1;
        while (true)
        {
            
            if (numbers[itr1] + numbers[itr2] == target)
            {
                break;
            }
            
            if (numbers[itr2] > target)
            {
                itr2--;
            }
            else if (itr1 < itr2 - 1)
            {
                itr1++;
            }
            else
            {
                itr2--;
                itr1 = 0;
            }
            
        }
        
        
        
        return {itr1+1, itr2+1};
    }
};