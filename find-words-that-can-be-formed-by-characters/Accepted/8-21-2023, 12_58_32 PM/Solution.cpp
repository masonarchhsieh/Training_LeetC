// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt = 0;
        unordered_map<char, int> char_map;
        for (size_t i = 0; i < chars.length(); ++i)
            char_map[chars[i]]++;
        
        for (auto i : words) {
            bool add = true;
            for (auto j = 0; j < i.length(); j++) {
                if (count(i.begin(), i.end(), i[j]) > char_map[i[j]]) {
                    add = false;
                    break;
                }
            }
            if (add)
                cnt += i.length();
        }

        return cnt;
    }
};