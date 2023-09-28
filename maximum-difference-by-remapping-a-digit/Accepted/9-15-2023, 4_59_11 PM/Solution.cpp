// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

class Solution {
public:
    int minMaxDifference(int num) {
        string s_max = to_string(num), s_min = to_string(num);
        for (int i = 0; i < s_max.length(); i++) {
            if (s_max[i] == '9')
                continue;
            for (int j = i + 1; j < s_max.length(); j++) {
                if (s_max[j] == s_max[i])
                    s_max[j] = '9';
            }
            s_max[i] = '9';
            break;
        }

        for (int j = 1; j < s_max.length(); j++) {
            if (s_min[j] == s_min[0])
                s_min[j] = '0';
        }
        s_min[0] = '0';
        cout << s_max << ", " << s_min << endl;

        return stoi(s_max) - stoi(s_min);
    }
};