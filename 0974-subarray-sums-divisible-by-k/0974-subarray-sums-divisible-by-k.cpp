class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int current_sum = 0, res = 0;
        m[0] = 1;               // initial

        for (auto i = 0; i < size(nums); i++) {
            current_sum += nums.at(i);
            int rem = current_sum % k;
            // the remainder may be a negative num
            rem = (rem < 0)? rem += k : rem;
            if (m.find(rem) != m.end())
                res += m[rem];
            m[rem]++;
        }

        return res;
    }
};