class Solution {
    static bool compare(const char &c1, const char &c2) {
        return c1 > c2;
    }
    bool isVow(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> pos;

        for (size_t i = 0; i < s.length(); i++) {
            if (isVow(s[i])) {
                vowels.push_back(s[i]);
                pos.push_back(i);
            }
        }

        sort(vowels.begin(), vowels.end());
        for (auto i = 0; i < pos.size(); i++) {
            s[pos[i]] = vowels.at(i);
        }
        return s;
    }
};