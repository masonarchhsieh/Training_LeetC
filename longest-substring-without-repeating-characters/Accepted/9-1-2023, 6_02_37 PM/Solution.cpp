// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = (s.length() > 0);
        int left = 0, right = 0;
        unordered_map<char, int> m;     
        
        while (right < s.length()) {
            // find the repeated character
            if (m.find(s[right]) != m.end()) {
                res = max(res, right - left);
                left = max(left, m[s[right]] + 1);
                m[s[right]] = right;
                right++;
            } 
            // no repeated character
            else {
                m[s[right]] = right;
                right++;
            }
        }
        res = max(res, right - left);
        
        return res;
    }
};