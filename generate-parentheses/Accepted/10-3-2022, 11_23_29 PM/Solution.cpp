// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, 0, 0, n, "");
        return ans;
    }
    
    void helper(vector<string>& ans, int open, int close, int n, string per) {
        if (per.length() == n * 2) {
            ans.push_back(per);
            return;
        }
        
        if (open < n)
            helper(ans, open + 1, close, n, per + "(");
        if (close < open)
            helper(ans, open, close + 1, n, per + ")");
    }
};