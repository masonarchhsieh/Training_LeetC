class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t found;
        while ((found = s.find(part)) != std::string::npos) {
            s = s.substr(0, found) + s.substr(found + part.length());
        }

        return s;
    }
};