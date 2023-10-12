class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int, int> m;
        long long n_nums = 0;
        for (auto start = 0, end = 0; end < size(nums); end++) {
            m[nums[end]]++;
            n_nums += m[nums[end]] - 1;

            while (n_nums >= k) {
                res += (size(nums) - end);
                m[nums[start]]--;
                n_nums -= m[nums[start]];
                start++;
            }
        }

        return res;
    }
};