// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> j_set;
        for (size_t i = 0; i < jewels.length(); i++)
            j_set.insert(jewels[i]);
        int cnt = 0;
        for (size_t i = 0; i < stones.length(); i++) {
            if (j_set.find(stones[i]) != j_set.end())
                cnt++;
        }
        return cnt;
    }
};