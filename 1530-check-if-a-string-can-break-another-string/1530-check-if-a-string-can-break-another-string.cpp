class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        if (size(s1) != size(s2))
            return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return helper(s1, s2) | helper(s2, s1);
    }

    bool helper(const string& s1, const string& s2) {
        for (size_t i = 0; i < size(s1); i++)
            if (s1[i] < s2[i])
                return false;
        return true;
    }
};