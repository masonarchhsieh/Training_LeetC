class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = *max_element(begin(nums), end(nums));
        auto r = 0, l = 0;
        long long occ = 0;
        long long cnt = 0;
        while (r < nums.size()) {
            occ += (nums[r++] == max_num);
            while (occ >= k) {
                occ -= (nums[l++] == max_num);
                cnt += nums.size() - r + 1;
            }
        }

        return cnt;
    }
};