class Solution {
    vector<int> fibs;
public:
    int findMinFibonacciNumbers(int k) {
        fibs.clear();
        generateFibs(k);
        int idx = fibs.size() - 1;
        int res = 0;
        
        while (k > 0) {
            for (; idx >= 0; idx--)
                if (fibs[idx] <= k)
                    break;
            k -= fibs[idx];
            res++;
        }
        return res;
    }
    

    void generateFibs(int n) {
        fibs.push_back(1);
        fibs.push_back(1);
        for (int i = 2; ; i++) {
            fibs.push_back(fibs[i - 1] + fibs[i - 2]);
            if (fibs[i] + fibs[i - 1] > n)
                break;
        }
    }
};