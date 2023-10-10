class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> m;
        long long bad_pairs = size(nums) * ((size(nums) - 1)) / 2;
        for (auto i = 0; i < size(nums); i++)
            m[nums[i] - i]++;
        for (auto i : m)
            bad_pairs -= (i.second <= 1)? 0 :
                        (i.second * (i.second - 1) / 2);
        return bad_pairs;
    }
};