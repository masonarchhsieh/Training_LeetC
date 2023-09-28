// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
    vector<char> vows = { 'a', 'e', 'i', 'o', 'u' , 'A', 'E', 'I', 'O', 'U' };
public:
    string reverseVowels(string s) {
        vector<char> vows_list;
        for (auto i = 0; i < s.length(); i++)
            if (find(vows.begin(), vows.end(), s[i]) != vows.end())
                vows_list.push_back(s[i]);

        int rev_idx = vows_list.size() - 1;
        for (auto i = 0; i < s.length(); i++)
            if (find(vows.begin(), vows.end(), s[i]) != vows.end())
                s[i] = vows_list[rev_idx--];
        return s;
    }
};