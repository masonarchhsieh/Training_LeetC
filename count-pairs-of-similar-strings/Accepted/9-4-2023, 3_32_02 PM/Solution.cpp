// https://leetcode.com/problems/count-pairs-of-similar-strings

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        for (auto i = 0; i < words.size() - 1; i++) {
            for (auto j = i + 1; j < words.size(); j++) {
                if (isInSet(words[i], words[j]))
                    cnt++;
            }
        }
        return cnt;
    }

    bool isInSet(string s1, string s2) {
        unordered_set<char> set_s1, set_s2;
        for (auto i = 0; i < s1.length(); i++)
            set_s1.insert(s1[i]);
        for (auto j = 0; j < s2.length(); j++)
            set_s2.insert(s2[j]);
        if (set_s1.size() != set_s2.size())
            return false;
        for (auto i : s1)
            if (set_s2.find(i) == set_s2.end())
                return false;
        return true;
    }
};