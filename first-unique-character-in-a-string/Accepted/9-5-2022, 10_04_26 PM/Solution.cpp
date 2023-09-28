// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mymap;
        map<char, int>::iterator it;
        
        for (int i=0; i<s.length(); i++) {
            if (mymap.find(s[i]) == mymap.end()) {
                mymap[s[i]] = 1;
            }
            else
                mymap[s[i]] += 1;
        }
        
        int res = -1;
        
        for (int i=0; i<s.length(); i++) {
            if (mymap[s[i]] == 1)
            {
                res = i;
                break;
            }
        }
        
        return res;
    }
};