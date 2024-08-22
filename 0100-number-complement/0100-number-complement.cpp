class Solution {
public:
    int findComplement(int num) {
        if (num == 1)
            return 0;

        return (findComplement(num>>1) << 1) + (num & 0x1) ^ 0x1;
    }
};