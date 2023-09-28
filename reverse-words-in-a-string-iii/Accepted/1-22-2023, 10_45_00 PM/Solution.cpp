// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        int s_length = s.length();
        int itr = 0;
        char space = ' ';
        stack<char> str_stack;


        while (itr <= s_length) {
            if (s[itr] == space || itr == s_length)
            {
                int i = 0, pos = itr - str_stack.size();
                while (!str_stack.empty()) {
                    s[pos + i] = str_stack.top();
                    str_stack.pop();
                    i++;
                } 
            }
            else
                str_stack.push(s[itr]);

            itr++;
        }

        return s;
    }
};