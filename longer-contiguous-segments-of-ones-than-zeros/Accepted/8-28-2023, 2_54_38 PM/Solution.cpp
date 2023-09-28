// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros

class Solution {
public:
    bool checkZeroOnes(string s) {
        size_t idx = 0;
        int max_zero = 0, max_one = 0;
        while (idx < s.length()) {
            auto i = idx + 1;
            for (; i < s.length(); i++)
                if (s[idx] != s[i])
                    break;
            // it reaches to the end that idx is not the same
            if (s[idx] == '1')
                max_one = max(max_one, (int) (i - idx));
            else
                max_zero = max(max_zero, (int) (i - idx));
            idx = (s[idx] == s[i])? i+1 : i;
        }

        return max_one > max_zero;
    }
};