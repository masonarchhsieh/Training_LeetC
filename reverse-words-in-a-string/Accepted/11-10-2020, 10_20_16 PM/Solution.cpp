// https://leetcode.com/problems/reverse-words-in-a-string

#include <iostream>
#include <string>
class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        int slow = 0, fast = 0;
        
        while (fast < s.length()) {
            if (slow != fast && (s[fast] == ' ' || (fast == s.length() - 1 && s[fast] != ' '))) {
                string temp;
                if (fast == s.length()-1 && s[fast] != ' ')
                    temp.assign(s, slow, fast - slow + 1);
                else
                    temp.assign(s, slow, fast - slow);
                res.push_back(temp);
            }
            
            if (slow == fast && slow == s.length()-1 && s[slow] != ' ') {
                string temp;
                temp.assign(s, slow, 1);
                res.push_back(temp);
            }
            
            
            if (s[fast] == ' ')
                slow = fast + 1;
            fast++;
        }
        
        
        
        reverse(res.begin(), res.end());
        string re;
        for (int i=0; i<res.size(); i++) {
            if (i==0)
                re = res[i];
            else
                re = re + " " + res[i];
        }
        
        return re;
    }
    
};