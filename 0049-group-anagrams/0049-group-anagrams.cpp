class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<multiset<char>, int> m;
        for (auto i : strs) {
            multiset<char> _set;
            for (auto j : i)
                _set.insert(j);
            if (m.find(_set) == m.end()) {
                m[_set] = res.size();
                vector<string> s = { i };
                res.push_back(s);
            } else {
                res[m[_set]].push_back(i);
            }
        }
        
        
        return res;
    }
};