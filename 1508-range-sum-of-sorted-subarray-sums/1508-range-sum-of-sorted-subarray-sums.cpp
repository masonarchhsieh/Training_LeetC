class Solution {
    const int MODULE = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> array;
        for (auto l = 0; l < size(nums); l++) {
            long long sum = nums.at(l);
            array.push_back(sum);
            for (auto r = l + 1; r < size(nums); r++) {
                sum = (nums.at(r) + sum);
                array.push_back(sum);
            }
        }

        sort(begin(array), end(array));
        return std::accumulate(begin(array) + left - 1, begin(array) + right, (long long)0) % MODULE;
    }
};