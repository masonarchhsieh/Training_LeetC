// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto i = 0; i < letters.size(); i++) {
            if (letters[i] > target) 
                return letters[i];
        }

        return letters[0];
    }
};