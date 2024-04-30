class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long cnt = 0;
        int prefix = 0;
        vector<int> count(1024, 0);
        count[0] = 1;

        for (auto c : word) {
            prefix ^= (1 << (c - 'a'));
            cnt += count[prefix];
            /* noted that:
                Given a string word that consists of the first ten lowercase English letters 
                ('a' through 'j'), return the number of wonderful non-empty substrings in word.
            */
            for (auto i = 0; i < 10; i++) {
                cnt += count[prefix ^ 1 << i];
            }
            count[prefix]++;
        }

        return cnt;
    }
}; 