class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribonacci_(38, 0);
        tribonacci_[1] = 1;
        tribonacci_[2] = 1;

        for (auto i = 3; i <= n; i++) {
            tribonacci_[i] = tribonacci_[i-1] + tribonacci_[i-2] + tribonacci_[i-3];
        }

        return tribonacci_[n];
    }
};