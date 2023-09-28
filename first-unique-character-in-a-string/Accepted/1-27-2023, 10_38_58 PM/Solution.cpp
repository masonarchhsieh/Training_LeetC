// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mymap;
        map<char, int>::iterator it;

        for (auto i = 0; i < s.length(); i++) {
            mymap[s[i]]++;
        }
        
        for (auto i = 0; i < s.length(); i++) {
            if (mymap[s[i]] == 1)
                return i;
        }

        return -1;
    }
};