// https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int balance = 0;
        size_t idx = 0;
        int count_z = 0, count_o = 0;

        while (idx < s.length()) {
            size_t i = idx;
            if (s[idx] == '0') {
                count_z = 0;
                for (; i < s.length(); i++) {
                    if (s[i] != '0')
                        break;
                    count_z++;
                }
                idx = i;
            }
            // "1"
            else {
                count_o = 0;
                for (; i < s.length(); i++) {
                    if (s[i] != '1')
                        break;
                    count_o++;
                }
                if (count_z == count_o)
                    balance = max(balance, count_z + count_o);
                else if (count_z < count_o && count_z != 0)
                    balance = max(balance, 2 * count_z);
                else if (count_z > count_o && count_o != 0)
                    balance = max(balance, 2 * count_o);
                idx = i;
            }
        }

        return balance;
    }
};