class Solution {
    const int MODULE = 1000000007;
public:
    int numSub(string s) {
        long long res = 0;

        for (auto start = 0, end = 0; end < size(s); end++) {
            if (s[end] == '1') {
                start = end;
                while (s[end] == '1') {
                    end++;
                }
                res += getTriangleNum(end - start);
                res %= MODULE;
            }
        }

        return res;
    }

    long long getTriangleNum(long long n) {
        if (n < 2)
            return n;
        return (n + 1) * n / 2;
    }
};