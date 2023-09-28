// https://leetcode.com/problems/number-of-different-integers-in-a-string

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> t;
        bool nxt_digit = false;
        for (size_t i = 0; i < word.length(); ++i) {
            string num = "";
            while (i < word.length() && !isdigit(word[i]))
                i++;
            while (i < word.length() && isdigit(word[i]))
                num += word[i++];
            int j = 0;
            while (j < num.length() && num[j] == '0')
                j++;
            if (!empty(num))
                t.insert(num.substr(j));
        }
        return t.size();
    }
};