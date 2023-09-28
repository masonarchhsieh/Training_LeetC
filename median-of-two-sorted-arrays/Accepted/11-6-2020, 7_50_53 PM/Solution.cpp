// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int target = (m + n) / 2;
        bool even = ((m + n)%2 == 0)? true : false;
        vector<int> final;
        
        int itr1 = 0, itr2 = 0;
        double res = 0.00;
        
        while (itr1 < m || itr2 < n) {
            if (itr1 >= m) {
                final.push_back(nums2[itr2]);
                itr2++;
            }
            else if (itr2 >= n || (itr1 < m && nums1[itr1] <= nums2[itr2])) {
                final.push_back(nums1[itr1]);
                itr1++;
            } else {
                final.push_back(nums2[itr2]);
                itr2++;
            }
        }
        
        
        if (even)
            res = (double) (final[target] + final[target-1]) / 2.00;
        else
            res = (double) final[target];
        
        return res;
        
    }
};