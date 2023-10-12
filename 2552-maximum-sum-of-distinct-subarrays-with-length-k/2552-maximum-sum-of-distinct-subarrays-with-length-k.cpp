class Solution {
public:
    // sliding window
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0;
        unordered_set<int> _set;
        long long window_sum = 0;

        for (auto start = 0, end = 0; end < size(nums); end++) {
            window_sum += nums.at(end);
            
            while (!_set.empty() && (_set.find(nums[end]) != _set.end() || _set.size() >= k)) {
                _set.erase(nums.at(start));
                window_sum -= nums.at(start);
                start++;
            }
            _set.insert(nums.at(end));
            if (end - start + 1 == k)
                res = max(res, window_sum);
        }

        return res;
    }
};