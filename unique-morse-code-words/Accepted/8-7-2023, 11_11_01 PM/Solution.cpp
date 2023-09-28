// https://leetcode.com/problems/unique-morse-code-words

class Solution {
    string mos_code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> unique_morse;

        for (auto i : words) {
            string tmp;
            for (auto j = 0; j < i.length(); j++) {
                tmp += mos_code[i[j] - 'a'];
            }

            if (find(unique_morse.begin(), unique_morse.end(), tmp) == unique_morse.end())
                unique_morse.push_back(tmp);
        }

        return unique_morse.size();
    }
};