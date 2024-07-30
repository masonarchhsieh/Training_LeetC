class Solution {
public:
    int minimumDeletions(string s) {
        int num_a = count(s.begin(), s.end(), 'a');
        int cur_b = s[0] == 'b';
        int res = cur_b + num_a - 1;

        for (auto i = 1; i < s.length(); i++) {
            cur_b += (s[i] == 'b');
            num_a -= (s[i - 1] == 'a');
            res = min(res, cur_b + num_a - 1);
        }

        return res;
    }
};