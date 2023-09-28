// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int pos_a = a.length() - 1, pos_b = b.length() - 1;
        int carry = 0;

        while (pos_a >= 0 || pos_b >= 0 || carry) {
            if (pos_a >= 0) {
                carry += a[pos_a] - '0';
                pos_a--;
            }
            if (pos_b >= 0) {
                carry += b[pos_b] - '0';
                pos_b--;
            }
            res += carry % 2 + '0';
            carry /= 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};