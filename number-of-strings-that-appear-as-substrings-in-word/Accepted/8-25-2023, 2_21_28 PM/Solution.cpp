// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto i : patterns) {
            if (word.find(i) != std::string::npos)
                cnt++;
        }

        return cnt;
    }
};