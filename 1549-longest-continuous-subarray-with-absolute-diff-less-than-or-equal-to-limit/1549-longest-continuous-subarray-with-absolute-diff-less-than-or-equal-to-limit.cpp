class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        multiset<int> s;
        for (auto l = 0, r = 0; r < size(nums); r++) {
            s.insert(nums[r]);
            while (!s.empty() && *(s.rbegin()) - *(s.begin()) > limit) {
                s.erase(s.find(nums[l++]));
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};