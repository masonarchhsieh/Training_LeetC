class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> target;
        for (auto i = 0; i < n; i++)
            target.push_back(i);
        
        vector<int> p = target;
        int res = 0;
        while (true) {
            p = permute(p, n);
            res++;
            if (target == p)
                break;
        }
        return res;
    }

    vector<int> permute(vector<int>& p, int n) {
        vector<int> arr(p.size(), 0);
        for (auto i = 0; i < p.size(); i++) {
            if (i % 2 == 0)
                arr[i] = p[i / 2];
            else
                arr[i] = p[n / 2 + (i - 1) / 2];
        }
        return arr;
    }
};