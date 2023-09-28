// https://leetcode.com/problems/keep-multiplying-found-values-by-two

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int>::iterator found = find(nums.begin(), nums.end(), original);

        while (found != nums.end()) {
            original *= 2;
            found = find(nums.begin(), nums.end(), original);
        }


        return original;
    }
};