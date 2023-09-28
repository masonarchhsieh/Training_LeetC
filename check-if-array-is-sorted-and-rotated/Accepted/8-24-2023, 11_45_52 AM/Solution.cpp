// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        if (tmp == nums)
            return true;
        for (auto i = 0; i < nums.size(); i++) {
            vector<int> t1(nums.begin(), nums.begin() + i + 1);
            vector<int> t2(nums.begin() + i + 1, nums.end());
            t2.insert(t2.end(), t1.begin(), t1.end());
            if (t2 == tmp)
                return true;
        }

        return false;
    }
};