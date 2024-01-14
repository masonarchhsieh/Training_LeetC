class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (size(word1) != size(word2))
            return false;
        map<char, int> m1, m2;
        multiset<int> s1, s2;
        set<char> s1_c, s2_c;
        for (auto i = 0; i < size(word1); i++) {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        
        for (auto i : m1) {
            s1.insert(i.second);
            s1_c.insert(i.first);
        }
        for (auto i : m2) {
            s2.insert(i.second);
            s2_c.insert(i.first);
        }

        return (s1 == s2) && (s1_c == s2_c);
    }
};