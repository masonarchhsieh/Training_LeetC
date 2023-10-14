class Solution {
public:
    std::string helper(std::string s, size_t &idx) {
        std::string res;
        while (idx < size(s) && s.at(idx) != ']') {
            if (!isdigit(s.at(idx))) {
                res.push_back(s.at(idx++));
                continue;
            }
            int n = 0;
            while (idx < size(s) && isdigit(s.at(idx)))
                n = n * 10 + s[idx++] - '0';
            idx++;
            std::string tmp = helper(s, idx);
            idx++;
            for (auto i = 0; i < n; i++)
                res += tmp;
        }
        return res;
    }

    string decodeString(string s) {
        size_t idx = 0;
        return helper(s, idx);
    }
};