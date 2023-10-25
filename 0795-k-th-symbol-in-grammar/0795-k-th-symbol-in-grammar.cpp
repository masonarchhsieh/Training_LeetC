class Solution {
public:
    // do NOT bit-wise operation on n
    int kthGrammar(int n, int k) {
        if (k == 1)
            return 0;
        
        int prev_len = 1 << (n - 2);
        if (k <= prev_len)
            return kthGrammar(n - 1, k);
        int res = kthGrammar(n - 1, k - prev_len);
        return res == 1? 0 : 1;
    }
};