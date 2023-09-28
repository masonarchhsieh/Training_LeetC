// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        map<char, int> map_s, map_t;
        
        for (int i=0; i<s.length(); i++)
            map_s[s[i]]++;
        for (int i=0; i<t.length(); i++)
            map_t[t[i]]++;
        
        for (int i=0; i<26; i++)
            if (map_s['a' + i] != map_t['a' + i])
                return false;
        
        return true;
    }
};