// https://leetcode.com/problems/rearrange-words-in-a-sentence

#include <algorithm> 
static bool Pred (string &a, string &b)
{
    return a.length() < b.length();
}

class Solution {
public:
    string arrangeWords(string text) {       
        stringstream sstr;
        vector<string> tmp; 
        map<int, vector<string>> my_map;
        map<int, vector<string>>::iterator it;
        
        sstr << text;
        string s;
        while (!sstr.eof())
        {
            sstr >> s;
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            it = my_map.find(s.length());
            
            if (it != my_map.end())
                my_map[s.length()].push_back(s);
            else
                my_map.insert(pair<int,vector<string>>(s.length(), vector<string>{s}));
        }
      
        string res;
        for (it=my_map.begin(); it != my_map.end(); ++it)
        {
            if (it != my_map.begin())
                res += " ";
            for (int i=0; i<it->second.size(); i++)
            {
                res += it->second[i];
                if (i != it->second.size() - 1)
                    res+=" ";
            }
        }
        std::transform(res.begin(), res.begin()+1, res.begin(), ::toupper);

        return res;

    }
};