class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        auto word1_idx = 0, word2_idx = 0;

        while (word1_idx < size(word1) || word2_idx < size(word2)) {
            if (word1_idx >= size(word1)) {
                res += word2.substr(word2_idx);
                break;
            }
            if (word2_idx >= size(word2)) {
                res += word1.substr(word1_idx);
                break;
            }
            res.push_back(word1[word1_idx++]);
            res.push_back(word2[word2_idx++]);                        
        }
        return res;
    }
};