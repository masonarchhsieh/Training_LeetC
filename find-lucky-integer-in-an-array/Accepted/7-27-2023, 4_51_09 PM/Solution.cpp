// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res = -1;
        sort (arr.begin(), arr.end());
        unordered_map<int, int> m;

        for (auto i : arr)
            m[i]++;
        for (auto i : m)
            if (i.second == i.first)
                if (i.first > res)
                    res = i.first;
        return res;
    }   
};