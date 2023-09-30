class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        int steps = 0;
        unordered_map<char, int> s_map, t_map;
        for (size_t i = 0; i < n; i++) {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }

        for (auto i : s_map) {
            if (t_map.find(i.first) == t_map.end()) {
                steps += i.second;
            } else if (i.second > t_map[i.first]){
                steps += (i.second - t_map[i.first]);
            }
        }
        return steps;
    }
};