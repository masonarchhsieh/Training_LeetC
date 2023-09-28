// https://leetcode.com/problems/circular-sentence

class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        vector<string> words;
        while (ss) {
            string s;
            ss >> s;
            if (s.length() > 0)
                words.push_back(s);
        }
        
        if (words.size() == 1)
            return words[0][0] == words[0][words[0].length() - 1];
        for (auto i = 1; i < words.size(); i++)
            if (words[i][0] != words[i-1][words[i-1].length() - 1])
                return false;

        return words[0][0] == words[words.size() - 1][words[words.size() - 1].length() - 1];
    }
};