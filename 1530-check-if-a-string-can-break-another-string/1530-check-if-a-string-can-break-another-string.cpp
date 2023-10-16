class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        multiset<char> s1_set, s2_set;
        for (auto i = 0; i < size(s1); i++) {
            s1_set.insert(s1[i]);
            s2_set.insert(s2[i]);
        }

        int mode = -1;
        for (multiset<char>::iterator it_s1 = s1_set.begin(), it_s2 = s2_set.begin(); it_s1 != s1_set.end() && it_s2 != s2_set.end(); ++it_s1, ++it_s2) {
            if (mode < 0) {
                if (*it_s1 < *it_s2)
                    mode = 1;
                else if (*it_s1 > *it_s2)
                    mode = 2;
            }
            
            if (mode == 1) {
                if (*it_s1 > *it_s2)
                    return false;
            }
            else if (mode == 2) {
                if (*it_s1 < *it_s2)
                    return false;
            }
        }

        return true;;
    }
};