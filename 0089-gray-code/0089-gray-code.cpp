class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if (n == 0)
            return res;
        res.push_back(1);
        int cur = 1;
        for (int i = 2; i <= n; i++) {
            cur <<= 1;
            for (int j = size(res) - 1; j >= 0; j--)
                res.push_back(cur + res[j]);
        }

        return res;
    }
};