class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(begin(expected), end(expected));
        int cnt = 0;
        for (auto i = 0; i < size(heights); i++)
            cnt += (expected[i] != heights[i]);

        return cnt;
    }
};