class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while (a > 0 || b > 0 || c > 0) {
            if (c & 0x1) {
                if (!(a & 0x1 | b & 0x1))
                    flips++;
            }
            else
                flips += (a & 0x1) + (b & 0x1);

            c >>= 1;
            b >>= 1;
            a >>= 1;
        }

        return flips;
    }
};