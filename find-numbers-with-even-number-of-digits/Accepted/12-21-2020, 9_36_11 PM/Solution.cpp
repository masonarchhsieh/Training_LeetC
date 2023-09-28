// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even_digits = 0;
        
        for (int i=0; i<nums.size(); i++) {
            string n = to_string(nums[i]);
            if (n.length() % 2 == 0)
                even_digits++;
        }
        return even_digits;
    }
};