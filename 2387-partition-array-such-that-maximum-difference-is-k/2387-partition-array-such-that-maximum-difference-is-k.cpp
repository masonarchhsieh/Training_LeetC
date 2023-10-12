class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1;
        int local_min = nums.at(0), local_max = nums.at(0);

        for (auto i = 0; i < size(nums); i++) {
            local_min = min(nums.at(i), local_min);
            local_max = max(nums.at(i), local_max);

            if (local_max - local_min > k) {
                local_min = local_max;
                res++;
            }
        }

        return res;
    }
};