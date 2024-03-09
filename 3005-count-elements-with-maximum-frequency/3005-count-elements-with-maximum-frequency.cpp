class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int res = 0, max_freq = 0;
        sort(begin(nums), end(nums));

        for (auto i = 0; i < nums.size();) {
            auto j = i;
            while (j < nums.size() && nums[j] == nums[i]) {
                j++;
            }
            int freq = j - i;
            i = j;
            if (max_freq < freq) {
                max_freq = freq;
                res = freq;
                continue;
            }
            if (max_freq == freq)
                res += freq;
        }

        return res;
    }
};