// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            cout << mid << endl;
            if (nums.at(mid) == target)
                return mid;
            if (nums.at(mid) < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};