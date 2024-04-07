class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0;

        for (auto c : s) {
            if (c == '(') {
                l++;
                r++;
            } else if (c == ')') {
                l--;
                r--;
            } else {
                l--;
                r++;
            }
            if (r < 0)
                return false;
            l = (l < 0)? 0 : l;
        }
        return l == 0;
    }
};