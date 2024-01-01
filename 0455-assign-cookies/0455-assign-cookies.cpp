class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, _child = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (i = 0; i < size(s) && _child < size(g); i++)
            if (g[_child] <= s[i])
                _child++;
                
        return _child;
    }
};