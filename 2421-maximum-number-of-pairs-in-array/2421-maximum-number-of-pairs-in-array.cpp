class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n_pairs = 0, n_uniq_nums = 0;
        unordered_map<int, int> m;
        for (auto i : nums)
            m[i]++;
        for (auto i : m) {
            n_pairs += (i.second / 2);
            n_uniq_nums += (i.second % 2);
        }

        return { n_pairs, n_uniq_nums };
    }
};