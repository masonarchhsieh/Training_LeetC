// https://leetcode.com/problems/maximum-69-number

class Solution {
public:
    int maximum69Number (int num) {
        string num_s = to_string(num);
        size_t left_6 = 0;

        while (left_6 < num_s.length()) {
            if (num_s[left_6] == '6') {
                num_s[left_6] = '9';
                break;
            }
            left_6++;
        }


        return stoi(num_s);
    }
};