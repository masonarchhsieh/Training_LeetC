// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool res = (s1 == s2);

        swap(s1[0], s1[2]);
        res |= (s1 == s2);

        swap(s1[1], s1[3]);
        res |= (s1 == s2);

        swap(s1[0], s1[2]);
        res |= (s1 == s2);

        return res;
    }
};