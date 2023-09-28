// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        if (nums1.size() == 0)
            return nums2;
        if (nums2.size() == 0)
            return nums1;

        vector<vector<int>> res, tmp;
        if (nums1[0].front() == nums2[0].front()) {
            res.push_back({nums1[0].front(), nums1[0].back() + nums2[0].back()});
            nums1.erase(nums1.begin());
            nums2.erase(nums2.begin());
        }
        else if (nums1[0].front() < nums2[0].front()) {
            res.push_back({nums1[0].front(), nums1[0].back()});
            nums1.erase(nums1.begin());
        }
        else if (nums1[0].front() > nums2[0].front()) {
            res.push_back({nums2[0].front(), nums2[0].back()});
            nums2.erase(nums2.begin());
        }
        tmp = mergeArrays(nums1, nums2);
        res.insert(res.end(), tmp.begin(), tmp.end());

        return res;
    }
};