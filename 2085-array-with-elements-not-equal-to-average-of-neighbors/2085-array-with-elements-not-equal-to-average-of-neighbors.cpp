class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        sort(nums.begin(), nums.end());

        for (auto i = 0; i < size(nums) / 2; i++) {
            res[i * 2] = nums[i];
            res[i * 2 + 1] = nums[size(nums) - 1 - i];
        }
        if (size(nums) % 2 == 1)
            res[res.size() - 1] = nums.at(nums.size() / 2);

        return res;
    }
};