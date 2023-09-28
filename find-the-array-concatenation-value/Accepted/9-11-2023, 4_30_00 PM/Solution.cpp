// https://leetcode.com/problems/find-the-array-concatenation-value

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        string t = to_string(nums.front()) + to_string(nums.back());
        nums.erase(nums.begin());
        nums.pop_back();

        return stoll(t) +  findTheArrayConcVal(nums);
    }
};