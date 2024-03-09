class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        
        while (i < size(nums1) && j < size(nums2)) {
            if (nums1.at(i) == nums2.at(j))
                return nums1.at(i);
            else if (nums1.at(i) < nums2.at(j))
                i++;
            else
                j++;
        }

        return -1;
    }
};