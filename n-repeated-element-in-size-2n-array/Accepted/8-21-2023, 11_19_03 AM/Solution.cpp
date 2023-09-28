// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (auto i : nums) {
            if (s.find(i) != s.end())
                return i;
            s.insert(i);
        }
        return -1;
    }
};