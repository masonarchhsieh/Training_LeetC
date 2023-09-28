// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        for (auto i : grid) {
            int left = 0, right = i.size() - 1;
            int count = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (i[mid] < 0) {
                    right = mid - 1;
                    count = i.size() - mid;
                }
                else {
                    left = mid + 1;
                }
            }
            sum += count;
        }

        return sum;
    }
};