class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = size(arr);
        vector<int> prefix(n + 1, 0);

        for (auto i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }

        int cnt = 0;
        for (auto i = 0; i < n; i++) {
            for (auto j = i + 1; j < n; j++) {
                if (prefix[i] == prefix[j + 1])
                    cnt += (j - i);
            }
        }
        return cnt;
    }
};