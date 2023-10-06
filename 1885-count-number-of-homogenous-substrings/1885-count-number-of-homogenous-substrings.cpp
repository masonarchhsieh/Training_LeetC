class Solution {
    const int MODULE = 1000000007;
public:
    int countHomogenous(string s) {
        long long res = 0;
        auto start = 0, end = 0;
        for (start = 0, end = 0; end < size(s);) {
            while (end < size(s)) {
                if (s[end] != s[start]) {
                    res += getTriangle(end - start);
                    res %= MODULE;
                    start = end;
                    break;
                }
                // s[end] == s[start]
                if (end == size(s) - 1) {
                    res += getTriangle(end - start + 1);
                    res %= MODULE;
                }
                end++;
            }
            start = end;
        }
        return res;
    }

    long long getTriangle(long long n) {
        if (n < 2)
            return n;
        return (n + 1) * n / 2;
    }
};