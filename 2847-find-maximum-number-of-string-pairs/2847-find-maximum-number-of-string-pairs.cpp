class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;

        for (auto i = 0; i < words.size(); i++) {
            for (auto j = i + 1; j < words.size(); j++) {
                if (IsSamePair(words[i], words[j])) {
                    string t = min(words[i], words[j]);
                    s.insert(t);
                    break;
                }
            }
        }


        return s.size();
    }

    bool IsSamePair(const string &s1, const string &s2) {
        if (s1 == s2)
            return true;
        return s1.front() == s2.back() && s1.back() == s2.front();
    }
};