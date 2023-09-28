// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        vector<string> zigzags(numRows, "");
        int index = 0, mode = 0;

        if (numRows == 1)
            return s;
        for (int i = 0; i < s.length(); i++) {
            zigzags[index] = zigzags[index] + s[i];
            if (mode == 0) {
                index++;
                if (index >= numRows) {
                    index = numRows - 2;
                    mode = 1;
                }
            } else {
                index--;
                if (index < 0) {
                    index = 1;
                    mode = 0;
                }
            }
        }

        for (auto i = 0; i < zigzags.size(); i++) {
            res = res + zigzags[i];
        }
        return res;
    }
};