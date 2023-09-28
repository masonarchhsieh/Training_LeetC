// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        vector<int> v;
        
        while (x > 0) {
            int t = x % 10;
            v.push_back(t);
            x = x / 10;
        }
        
        for (int i=0; i<v.size()/2; i++)
            if (v[i] != v[v.size()-1-i])
                return false;
        
        return true;
    }
};