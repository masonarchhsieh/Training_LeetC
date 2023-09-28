// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        for (auto i = 0; i < s.length(); i++)
            for (auto j = i + 1; j < s.length(); j++)
                if (s[j] > s[i] && (s[j] - '0') % 2 == (s[i] - '0') % 2)
                    swap(s[i], s[j]);
        return stoi(s);
    }
};