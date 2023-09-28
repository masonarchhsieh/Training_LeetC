// https://leetcode.com/problems/two-out-of-three

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;

        for (auto i = 0; i < nums1.size(); i++) {
            if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end() || 
                find(nums3.begin(), nums3.end(), nums1[i]) != nums3.end())
                res.push_back(nums1[i]);
        }

        for (auto i = 0; i < nums2.size(); i++) {
            if (find(nums3.begin(), nums3.end(), nums2[i]) != nums3.end())
                res.push_back(nums2[i]);
        }
        sort(res.begin(), res.end());
        vector<int>::iterator it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));

        return res;
    }
};