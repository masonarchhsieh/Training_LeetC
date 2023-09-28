// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        size_t t = 0;
        if (name[0] != typed[0])
            return false;
        for (size_t i = 1; i < name.length(); i++) {
            if (t >= typed.size())
                return false;
            if (name[i] != name[i - 1]) {
                for (;t < typed.length(); t++) {
                    if (typed[t] != name[i-1])
                        break;
                }
            } else {
                t++;
            }
            if (name[i] != typed[t])
                return false;   
        }
        for (t = t + 1; t < typed.length(); t++) {
            if (typed[t] != typed[t-1])
                return false;
        }
        return true;
    }
};