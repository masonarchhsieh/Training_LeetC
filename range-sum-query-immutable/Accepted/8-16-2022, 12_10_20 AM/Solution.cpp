// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        if (left < 0 || right >= nums.size())
            return 0;
        int res = 0;
        for (int i = left; i <= right; i++)
            res += nums[i];
        
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */