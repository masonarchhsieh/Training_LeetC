class Solution {
    unordered_map<string, vector<char>> m;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        m.clear();
        for (auto pyramid : allowed)
            m[pyramid.substr(0, 2)].push_back(pyramid.back());

        return dfs(bottom, 0, "");
    }

    bool dfs(string bottom, int i, string s) {
        if (size(bottom) == 1)
            return true;
        if (i == size(bottom) - 1)
            return dfs(s, 0, "");

        for (auto c : m[bottom.substr(i, 2)]) {
            s.push_back(c);
            if (dfs(bottom, i + 1, s))
                return true;
            s.pop_back();
        }
        return false;
    }
};