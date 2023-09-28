// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
                      
        return help(s, 0, s.length()-1, true);
    }
    
    bool help(string s, int front, int back, bool del) {
        if (front >= back)
            return true;
        
        if (s[front] != s[back]) {
            if (!del)
                return false;
            
            return help(s, front+1, back, false) || help(s, front, back-1, false);
        }
        while (front <= back && s[front] == s[back]) {
            front++;
            back--;
        }        

        return help(s, front, back, del);
    }
};