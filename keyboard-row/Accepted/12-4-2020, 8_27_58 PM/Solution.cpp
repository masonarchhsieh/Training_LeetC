// https://leetcode.com/problems/keyboard-row

class Solution {
    string key_rows[3] = {
        "qwertyiuop",
        "asdfgjhjkl",
        "zxcvbnm"
    };
public:
    int getRow(char c) {
        for (int i=0; i<3; i++) {
            for (int j=0; j<key_rows[i].length(); j++) {
                if (key_rows[i][j] == c)
                    return i;
            }
        }
        
        return -1;
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        
        for (int i=0; i<words.size(); i++) {
            int this_row = getRow(tolower(words[i][0]));
            bool add = true;
            for (int j=1; j<words[i].length(); j++) {
                if (getRow(tolower(words[i][j])) != this_row) {
                    add = false;
                    break;
                }
            }
            if (add)
                res.push_back(words[i]);
        }
        
        
        return res;
    }
};