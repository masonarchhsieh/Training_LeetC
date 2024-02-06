class Solution {
public:
    int firstUniqChar(string s) {
        unordered_set<char> _set;
        for (size_t i = 0; i < size(s); i++) {
            if (_set.find(s[i]) != _set.end())
                continue;
            bool uniq = true;
            for (size_t j = i + 1; j < size(s); j++) {
                if (s[i] == s[j]) {
                    uniq = false;
                    _set.insert(s[i]);
                    break;
                }
            }
            if (uniq)
                return i;
        }
        return -1;
    }
};