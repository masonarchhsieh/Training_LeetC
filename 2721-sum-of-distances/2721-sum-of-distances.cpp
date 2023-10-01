class Solution {
    unordered_map<int, vector<int>> m;
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> res;
        res.assign(nums.size(), 0);
        m.clear();
        travel(nums);

        for (auto i : m) {
            long long _sum = 0;
            for (auto j = 0; j < i.second.size(); j++) {
                _sum += i.second[j] - i.second[0];
            }
            res[i.second[0]] = _sum;
            for (auto j = 1; j < i.second.size(); j++) {
                _sum += (i.second[j] - i.second[j - 1]) * (2 * j - i.second.size());
                res[i.second[j]] = _sum;
            }
        }
        return res;
    }

    void travel(vector<int>& nums) {
        for (auto i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
    }
};