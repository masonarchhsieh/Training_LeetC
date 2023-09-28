// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) { 
        if(!needle.length())    return 0;
        
        size_t pos = haystack.find(needle);
        return (pos==string::npos)?-1:pos;
    }
};