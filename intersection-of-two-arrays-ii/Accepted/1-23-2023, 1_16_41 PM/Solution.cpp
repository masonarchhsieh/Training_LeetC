// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int itr1 = 0, itr2 = 0;

        while (itr1 < nums1.size() && itr2 < nums2.size()) {
            if (nums1[itr1] == nums2[itr2]) {
                res.push_back(nums1[itr1]);
                itr1++;
                itr2++;
            }
            else if (nums1[itr1] < nums2[itr2])
                itr1++;
            else
                itr2++;
        }

        return res;
    }
};