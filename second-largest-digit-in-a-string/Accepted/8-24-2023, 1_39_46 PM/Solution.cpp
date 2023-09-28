// https://leetcode.com/problems/second-largest-digit-in-a-string

class Solution {
public:
    int secondHighest(string s) {
        int largest = -1, second_larg = -1;
        for (size_t i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                if (s[i] - '0' > largest) {
                    second_larg = largest;
                    largest = s[i] - '0';
                }
                else if (s[i] - '0' != largest){
                    second_larg = max(second_larg, s[i] - '0');
                }
            }
        }
        return second_larg;
    }
};