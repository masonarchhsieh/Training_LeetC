class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum approach:
        // map: { prefixSum, count }
        map<int, int> m;
        int cnt = 0, current_sum = 0;
        m[0] = 1;

        for (auto i = 0; i < size(nums); i++) {
            current_sum += nums.at(i);
            int diff = current_sum - k;
            if (m.find(diff) != m.end())
                cnt += m[diff];
            m[current_sum]++;
        }

        return cnt;
    }
};