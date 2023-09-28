// https://leetcode.com/problems/rearrange-characters-to-make-target-string

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int res = INT_MAX;
        unordered_map<char, int> s_m, target_m;

        for (auto i = 0; i < target.length(); i++)
            target_m[target[i]]++;
        
        for (auto i = 0; i < s.length(); i++) {
            s_m[s[i]]++;
        }
        for (auto i : target_m) {
            if (s_m[i.first] == 0)
                return 0;
            res = min(res, s_m[i.first] / i.second);
        }
        return res;
    }
};