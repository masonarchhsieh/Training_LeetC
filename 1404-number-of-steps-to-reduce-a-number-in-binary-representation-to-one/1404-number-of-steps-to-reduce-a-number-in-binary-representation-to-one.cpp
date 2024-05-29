class Solution {
public:
    int numSteps(string s) { 
        int carry = 0, steps = 0;
        for (int i = size(s) - 1; i > 0; i--) {
            if ((s[i] - '0') + carry == 1) {
                steps += 2;
                carry = 1;
            } else {
                carry++;
            }
        }
        return steps + carry;
    }
};