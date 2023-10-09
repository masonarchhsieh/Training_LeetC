class Solution {
public:
    string reformatNumber(string number) {
        string _number;
        for (size_t i = 0; i < size(number); i++)
            if (isdigit(number[i]))
                _number.push_back(number[i]);
        
        return makeResult(_number);
    }

    string makeResult(string s) {
        if (s.length() == 0)
            return "";
        if (s.length() == 2)
            return s;
        if (s.length() == 4) {
            return s.substr(0, 2) + "-" + s.substr(2, 2);
        }   
        // s.length() > 4, or first time
        string t = makeResult(s.substr(3));
        if (t.length() == 0)
            return s.substr(0, 3);
        return s.substr(0, 3) + "-" + t;
    }
};