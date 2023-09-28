// https://leetcode.com/problems/reverse-only-letters

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int itr = 0, back_itr = S.length() - 1;
        
        while (itr < back_itr) {
            while (itr < back_itr && !isalpha(S[itr]))
                itr++;
            while (back_itr >= itr && !isalpha(S[back_itr]))
                back_itr--;
            
            if (itr < back_itr) {
                swap(S[itr], S[back_itr]);
            }
            
            itr++;
            back_itr--;
        }
        
        
        return S;
    }
};