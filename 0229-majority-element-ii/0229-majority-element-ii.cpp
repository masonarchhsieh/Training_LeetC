class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int req = nums.size() / 3;
        vector<int> v;
        sort(nums.begin(), nums.end());
        int left = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums.at(i) != nums.at(left)) {
                left = i;
            }
            // nums.at(left) == nums.at(i)
            if (i - left == req)
                v.push_back(nums[left]);
        }
        return v;
    }
};