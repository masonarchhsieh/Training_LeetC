class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> m;
        long long sum = accumulate(nums.begin(), nums.end(), 0ll) % p;
        if (sum == 0)
            return 0;
        m[0] = -1;
        int cur_sum = 0;
        int res = (int) size(nums);
        for (auto i = 0; i < size(nums); i++) {
            cur_sum = (cur_sum + nums.at(i)) % p;
            if (m.find((cur_sum - sum + p) % p) != m.end())
                res = min(res, i - m[(cur_sum - sum + p) % p]);
            m[cur_sum] = i;
        }
        return (res == size(nums))? -1 : res;
    }
};