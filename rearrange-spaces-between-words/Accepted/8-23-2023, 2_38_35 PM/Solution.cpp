// https://leetcode.com/problems/rearrange-spaces-between-words

class Solution {
public:
    string reorderSpaces(string text) {
        int num_spaces = 0;
        for (size_t i = 0; i < text.length(); i++)
            if (isspace(text[i]))
                num_spaces++;
        
        vector<string> tmp;
        istringstream ss(text);
        string word;
        while (ss) {
            ss >> word;
            tmp.push_back(word);
        }
        tmp.resize(tmp.size() - 1);
        string res;
        for (auto i = 0; i < tmp.size(); i++) {
            res += tmp[i];
            if (i != tmp.size() - 1)
                for (auto j = 0; j < num_spaces / (tmp.size() - 1); j++)
                    res += " ";
        }
        if ((tmp.size() - 1) == 0) {
            for (auto i = 0; i < num_spaces; i++)
                res += " ";
        }
        else {
            for (int i = 0; i < num_spaces % (tmp.size() - 1); i++)
                res += " ";
        }
        return res;
    }
};