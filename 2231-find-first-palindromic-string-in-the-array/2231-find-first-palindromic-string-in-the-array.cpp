class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto s : words) {
            bool isPalindrome = true;
            for (auto j = 0; j < size(s) / 2; j++) {
                if (s.at(j) != s.at(s.size() - 1 - j)) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome)
                return s;
        }

        return "";
    }
};