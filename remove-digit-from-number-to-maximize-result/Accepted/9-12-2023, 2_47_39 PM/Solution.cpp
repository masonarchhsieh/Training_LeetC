// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result

class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "";
        size_t found = number.find_first_of(digit);
        res = number.substr(0, found) + number.substr(found + 1, number.length() - found);
        
        while (found != std::string::npos) {
            found = number.find(digit, found + 1);
            if (found == std::string::npos) {
                break;
            }
            string tmp = number.substr(0, found) + number.substr(found + 1, number.length() - found);
            res = (res > tmp)? res : tmp;
        }  
        return res;
    }
};