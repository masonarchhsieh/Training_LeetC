// https://leetcode.com/problems/second-largest-digit-in-a-string

class Solution {
public:
    int secondHighest(string s) {
        vector<int> t;
        for (size_t i = 0; i < s.length(); i++) {
            if (isdigit(s[i]))
                t.push_back(s[i] - '0');
        }
        sort(t.begin(), t.end());
        vector<int>::iterator it = unique(t.begin(), t.end());
        t.resize(std::distance(t.begin(), it));
        if (t.size() < 2)
            return -1;
        return t[t.size() - 2];
    }
};