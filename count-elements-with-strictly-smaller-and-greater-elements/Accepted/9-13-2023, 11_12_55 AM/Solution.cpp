// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements

class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min_n = nums.front(), max_n = nums.back();
        int cnt = 0;
        for (auto i = 1; i < nums.size() - 1; i++) {
            cnt += (nums.at(i) != min_n && nums.at(i) != max_n);
        }

        return cnt;
    }
};