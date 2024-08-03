class Solution {
public:
    int countSeniors(vector<string>& details) {
        return std::count_if(begin(details), end(details), [](auto detail){ return detail[11] > '6' || (detail[11] == '6' && detail[12] > '0'); });
    }
};