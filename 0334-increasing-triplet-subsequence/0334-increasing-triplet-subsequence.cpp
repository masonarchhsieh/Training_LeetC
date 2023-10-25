class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = -1, second = -1;
        for (auto i = 0; i < size(nums); i++) {
            if (first == -1)
                first = i;
            else if (second == -1 && nums[i] > nums[first])
                second = i;
            else if (nums[i] <= nums[first])
                first = i;
            else if (nums[i] >= nums[first] && nums[i] < nums[second])
                second = i;
            else if (nums[i] > nums[second])
                return true;
        }

        return false;
    }
};