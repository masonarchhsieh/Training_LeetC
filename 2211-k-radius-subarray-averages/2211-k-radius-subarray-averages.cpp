class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0;
        vector<int> res(size(nums), -1);
        if (k == 0)
            return nums;
        if (k > size(nums) / 2)
            return res;
        for (auto l = 0, r = 0; r < size(nums); r++) {
            sum += nums[r];
            int index = (r + l) / 2;
            if (index < k)
                continue;
            res[index] = sum / (2 * k + 1);
            sum -= nums[l++];
        }

        return res;
    }
};