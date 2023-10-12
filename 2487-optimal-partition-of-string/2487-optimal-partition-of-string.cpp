class Solution {
public:
    int partitionString(string s) {
        int n_substrings = (s.length() > 0);
        unordered_set<char> _set;

        for (auto i = 0; i < size(s); i++) {
            if (_set.find(s.at(i)) != _set.end()) {
                _set.clear();
                n_substrings++;
            }
            _set.insert(s.at(i));
        }

        return n_substrings;
    }
};