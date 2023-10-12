class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for (char c : num) {
            while (s.length() != 0 && k > 0 && c < s.back()) {
                s.pop_back();
                k--;
            }
            if (s.length() != 0 || c != '0')
                s.push_back(c);
        }

        while (s.length() != 0  && k-- > 0) 
            s.pop_back();
        if (s.length() == 0)
            return "0";
        return s;
    }
};