class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto jumble_int = [&](int num) -> int {
            string digits = to_string(num);
            for (char &digit : digits) {
                digit = '0' + mapping[digit - '0'];
            }
            return stoi(digits);
        };

        unordered_map<int, int> m;
        for (auto num : nums) {
            if (m.find(num) == m.end()) {
                m[num] = jumble_int(num);
            }
        }
        sort(begin(nums), end(nums), [&](int a, int b) {
            return m[a] < m[b];
        });
        return nums;
    }
};