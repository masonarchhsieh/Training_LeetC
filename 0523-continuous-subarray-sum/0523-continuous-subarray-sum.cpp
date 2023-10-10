class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[nums.front() % k] = 0;
        nums[0] = nums[0] % k;

        for (auto i = 1; i < size(nums); i++) {
            int n = (nums.at(i) + nums.at(i - 1)) % k;
            if (n == 0)
                return true;
            else if (m.find(n) != m.end()) {
                if (m[n] < i - 1)
                    return true;
                nums[i] = n;
            } else {
                m[n] = i;
                nums[i] = n;
            }
        }

        return false;
    }
};