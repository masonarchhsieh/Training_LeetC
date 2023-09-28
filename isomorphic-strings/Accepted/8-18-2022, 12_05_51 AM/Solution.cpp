// https://leetcode.com/problems/isomorphic-strings

class Solution {
 
    
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char,char> hash_map;
        int mapped[257] = {0};
        
        int len = s.length();
        for (int i=0; i<len; i++)
        {
            if (hash_map.count(s[i])) {
                if (hash_map[s[i]] != t[i])
                    return false;
            } else {
                if (!mapped[t[i]]) {
                    hash_map[s[i]] = t[i];
                    mapped[t[i]] = true;
                }
                else
                    return false;
            }
        }
        return true;
    }
};