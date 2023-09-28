// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int turn = k % nums.size();
        std::vector<int>::iterator it;
        
        for (int i=0; i<turn; i++) {
            it = nums.begin();
            nums.insert(it, nums[nums.size() - 1]);
            nums.pop_back();
        }
    }
};