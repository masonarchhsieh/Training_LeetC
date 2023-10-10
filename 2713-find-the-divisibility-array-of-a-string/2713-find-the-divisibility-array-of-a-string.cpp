class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> div(size(word), 0);
        long long curr_sum = 0;

        for (auto i = 0; i < size(word); i++) {
            curr_sum = (curr_sum * 10 + word[i] - '0') % m;
            div[i] = (curr_sum == 0);
        }
        return div;
    }
};