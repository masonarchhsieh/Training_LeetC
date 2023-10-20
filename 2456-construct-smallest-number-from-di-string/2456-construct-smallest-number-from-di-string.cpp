class Solution {
    unordered_set<char> _set;
public:
    string smallestNumber(string pattern) {
        _set.clear();
        string res(10, '9');
        backtrack(pattern + 'D', "", 0, res);

        return res;
    }

    void backtrack(const string& pattern, string s, int index, string& res) {
        if (index == size(pattern)) {
            if (size(s) == size(pattern) && stoll(s) < stoll(res))
                res = s;
            return;
        }
        
        for (auto c = '1'; c <= '9'; c++) {
            if (index == 0) {
                _set.insert(c);
                backtrack(pattern, s + c, index + 1, res);
                _set.erase(c);
            } else {
                if (_set.find(c) != _set.end() || pattern[index - 1] == 'D' && (s[index - 1] == '1' || 
                c >= s[index - 1]) || pattern[index - 1] == 'I' && (s[index - 1] == '9' || c <= s[index - 1]))
                    continue;
                _set.insert(c);
                backtrack(pattern, s + c, index + 1, res);
                _set.erase(c);
            }
        }
    }
};