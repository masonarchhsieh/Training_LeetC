// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        
        for (auto i = 0; i < s.length(); i += k) {
            if (i + k <= s.length())
                res.push_back(s.substr(i, k));
            else {
                string tmp = s.substr(i, s.length() - i);
                while (tmp.length() != k)
                    tmp.push_back(fill);
                res.push_back(tmp);
            }
        }


        return res;
    }
};