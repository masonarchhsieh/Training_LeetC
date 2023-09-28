// https://leetcode.com/problems/find-the-k-beauty-of-a-number

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string num_s = to_string(num);
        int cnt = 0;
        for (auto i = 0; i <= num_s.length() - k; i++) {
            if (stoi(num_s.substr(i, k)) == 0)
                continue;
            if (num % stoi(num_s.substr(i, k)) == 0)
                cnt++;
        }

        return cnt;
    }
};