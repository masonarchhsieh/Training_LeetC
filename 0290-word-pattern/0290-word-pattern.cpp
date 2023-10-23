class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        stringstream ss(s);
        set<string> _set;

        for (int i=0; i<pattern.length(); i++)
        {
            string tmp;
            ss >> tmp;
            if (tmp == "")
                return false;
            if (m.find(pattern[i]) != m.end() && tmp != m[pattern[i]])
                return false;
            if (m.find(pattern[i]) == m.end() && _set.find(tmp) != _set.end())
                return false;
            m[pattern[i]] = tmp;
            _set.insert(tmp);
        }

        if (ss) {
            string tmp;
            ss >> tmp;
            if (tmp != "")
                return false;
        }
        
        return true;
    }
};