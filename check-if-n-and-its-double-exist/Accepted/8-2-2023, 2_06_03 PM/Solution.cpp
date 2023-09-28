// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (auto i = 0; i < arr.size(); i++) {
            for (auto j = 0; j < arr.size(); j++) {
                if (i == j)
                    continue;
                if (arr[i] == 2 * arr[j])
                    return true;
            }
        }

        return false;
    }
};