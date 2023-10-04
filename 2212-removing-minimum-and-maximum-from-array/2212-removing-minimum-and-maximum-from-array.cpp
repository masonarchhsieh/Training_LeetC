class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        
        int min_pos = (int) (min_element(nums.begin(), nums.end()) - nums.begin());
        int max_pos = (int) (max_element(nums.begin(), nums.end()) - nums.begin());

        int t1 = 1 + min(min_pos, max_pos) + nums.size() - max(min_pos, max_pos);
        int t2 = min(1 + max(min_pos, max_pos), (int) nums.size() - min(min_pos, max_pos));
        return min(t1, t2);
    }
};