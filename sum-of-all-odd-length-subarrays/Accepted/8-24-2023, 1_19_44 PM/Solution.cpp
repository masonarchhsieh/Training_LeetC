// https://leetcode.com/problems/sum-of-all-odd-length-subarrays

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for (auto i = 1; i <= arr.size(); i += 2) {
            for (auto j = 0; j <= arr.size() - i; j++) {
                for (auto k = 0; k < i; k++) {
                    res += arr[j + k];
                }
            }
        }
        return res;
    }
};