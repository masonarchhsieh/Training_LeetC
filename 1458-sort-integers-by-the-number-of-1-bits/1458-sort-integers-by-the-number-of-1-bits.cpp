constexpr int countBits(int n) {
    if (n == 0)
        return 0;
    return 1 + countBits(n & (n - 1));
}
class Solution {
    static bool compare(const int &n1, const int &n2) {
        int t1 = countBits(n1), t2 = countBits(n2);
        if (t1 == t2)
            return n1 < n2;
        return t1 < t2;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};