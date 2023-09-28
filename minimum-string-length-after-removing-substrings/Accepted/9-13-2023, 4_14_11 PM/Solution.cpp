// https://leetcode.com/problems/minimum-string-length-after-removing-substrings

class Solution {
public:
    int minLength(string s) {
        size_t found = s.find("AB");
        if (found == std::string::npos)
            found = s.find("CD");
        while (found != std::string::npos)
        {
            s.erase(found, 2);
            found = s.find("AB");
            if (found == std::string::npos)
                found = s.find("CD");
        }
        return s.length();
    }
};