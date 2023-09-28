// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> t_map, arr_map;
        if (target.size() != arr.size())
            return false;
        for (auto i : target)
            t_map[i]++;
        for (auto i : arr)
            arr_map[i]++;
        
        for (auto i : target)
            if (t_map[i] != arr_map[i])
                return false;
        return true;
    }
};