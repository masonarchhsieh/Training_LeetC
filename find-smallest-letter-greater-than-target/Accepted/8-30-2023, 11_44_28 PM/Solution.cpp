// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>::iterator it = upper_bound(letters.begin(), letters.end(), target);
        if (it != letters.end())
            return *it;
        return letters[0];
    }
};