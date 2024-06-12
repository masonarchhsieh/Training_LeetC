class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (auto i : nums) {
            switch (i) {
                case 0:
                    red++;
                    break;
                case 1:
                    white++;
                    break;
                default:
                    blue++;
                    break;
            }
        }
        for (auto i = 0; i < size(nums); i++) {
            nums[i] = (red-- > 0)? 0 : (white-- > 0)? 1 : 2;
        }
    }
};