// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> ransome_map;
        map<char, int> maga_map;
        
        for (int i=0; i<ransomNote.length(); i++)
            ransome_map[ransomNote[i]]++;
        for (int i=0; i<magazine.length(); i++)
            maga_map[magazine[i]]++;
        
        for (auto a : ransome_map) {
            if (maga_map.find(a.first) != maga_map.end())
            {
                if (a.second > maga_map[a.first])
                    return false;
            }
            else
                return false;
        }
        
        return true;
    }
};