class Solution {
public:
    string smallestString(string s) {
        size_t i = 0;
        while (s[i] == 'a') {
            i++;
        }

        bool update = false;
        for (i; i < s.length(); i++) {
            if (s[i] == 'a')
                break;
            s[i] = s[i] - 1;
            update = true;
        }

        if (!update) {
            s[s.length() - 1] = 'z';
        }
        return s;
    }
};