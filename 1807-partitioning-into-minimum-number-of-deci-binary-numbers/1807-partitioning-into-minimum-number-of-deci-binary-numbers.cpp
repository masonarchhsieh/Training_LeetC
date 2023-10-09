class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (size_t i = 0; i < size(n); i++) {
            res = max(res, n[i] - '0');
        }
        return res;
    }
};