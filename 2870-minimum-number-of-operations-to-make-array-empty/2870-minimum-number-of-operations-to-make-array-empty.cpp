class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        unordered_map<int, int> m;
        for (auto &i : nums)
            m[i]++;
        
        for (auto &i : m) {
            int occurrence = i.second;
            if (occurrence == 1)
                return -1;
            ops += occurrence / 3;
            if (occurrence % 3)
                ops++;
        }
        return ops;
    }
};