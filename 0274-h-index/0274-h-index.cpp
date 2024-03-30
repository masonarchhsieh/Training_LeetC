class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int res = 0;

        for (auto i = 0; i < size(citations) && citations[i] >= i + 1; i++) {
            res = i + 1;
        }

        return res;
    }
};