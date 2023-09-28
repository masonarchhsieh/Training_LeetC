// https://leetcode.com/problems/shuffle-string

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string base = s;
        for (int i=0; i<s.length(); i++)
            s[indices[i]] = base[i];
        
        return s;
    }
};