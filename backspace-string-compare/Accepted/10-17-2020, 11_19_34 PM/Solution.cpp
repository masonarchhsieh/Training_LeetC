// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string sres = "", tres = "";
        
        for (int i=0; i<S.length(); i++) {
            if (sres.length() > 0 && S[i] == '#')
                sres.erase(sres.begin() + sres.length() - 1);
            else if (S[i] != '#')
                sres += S[i];
        }
        
         for (int i=0; i<T.length(); i++) {
            if (tres.length() > 0 && T[i] == '#')
                tres.erase(tres.begin() + tres.length() - 1);
            else if (T[i] != '#')
                tres += T[i];
        }
        
        cout << sres << " " << tres << endl;
        
        return (sres == tres)? true:false;
    }
};