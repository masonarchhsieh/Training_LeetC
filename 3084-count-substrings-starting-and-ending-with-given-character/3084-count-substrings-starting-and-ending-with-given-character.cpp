class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = std::count(s.begin(), s.end(), c);


        return count * (count - 1) / 2 + count;
    }
};