// https://leetcode.com/problems/count-the-number-of-consistent-strings

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        unordered_set<char> allowed_set;
        for (auto i = 0; i < allowed.length(); i++)
            allowed_set.insert(allowed[i]);
        for (auto i : words) {
            bool count = true;
            for (size_t j = 0; j < i.length(); j++) {
                if (allowed_set.find(i[j]) == allowed_set.end()) {
                    count = false;
                    break;
                }
            }
            if (count)
                cnt++;
        }
        return cnt;
    }
};