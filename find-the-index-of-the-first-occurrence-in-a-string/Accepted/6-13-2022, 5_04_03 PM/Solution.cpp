// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
        size_t find_ptr = 0;
        
        find_ptr = haystack.find(needle);
        if (find_ptr != std::string::npos)
        {
            res = find_ptr;
        }
        
        return res;
    }
};