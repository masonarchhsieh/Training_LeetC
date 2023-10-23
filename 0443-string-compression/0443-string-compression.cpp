class Solution {
public:
    int compress(vector<char>& chars) {
        string res;
        auto l = 0, r = 0;
        auto index = 0;
        for (l = 0, r = 0; r < size(chars);) {
            l = r;
            while (r < size(chars) && chars.at(r) == chars.at(l)) {
                r++;
            }
            res.push_back(chars.at(l));
            if (r - l > 1)
                res += to_string(r - l);
        }

        chars.resize(size(res));
        for (auto i = 0; i < size(res); i++) {
            chars[i] = res[i];
        }

        return size(chars);
    }
};