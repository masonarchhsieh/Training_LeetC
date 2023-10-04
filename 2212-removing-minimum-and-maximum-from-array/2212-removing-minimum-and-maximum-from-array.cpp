class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int n = nums.size();
        int min_pos = 0;
        int max_pos = 0;
        
        for (auto i = 0; i < n; i++) {
            min_pos = (nums[i] < nums[min_pos])? i : min_pos;
            max_pos = (nums[i] > nums[max_pos])? i : max_pos;
        }
        int t1 = 1 + min(min_pos, max_pos) + nums.size() - max(min_pos, max_pos);
        int t2 = min(1 + max(min_pos, max_pos), (int) nums.size() - min(min_pos, max_pos));
        return min(t1, t2);
    }
};