// https://leetcode.com/problems/min-max-game

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> t;
        for (auto i = 0; i < nums.size(); i += 2) {
            if ((i / 2) % 2 == 0)
                t.push_back(min(nums[i], nums[i + 1]));
            else
                t.push_back(max(nums[i], nums[i + 1]));
        }

        return minMaxGame(t);
    }
};