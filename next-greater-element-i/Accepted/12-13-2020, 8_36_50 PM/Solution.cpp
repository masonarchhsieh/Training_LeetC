// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int>::iterator it;
        for (int i=0; i<nums1.size(); i++) {
            it = find(nums2.begin(), nums2.end(), nums1[i]);
            if (it == nums2.end()) {
                res.push_back(-1);
                continue;
            }
            
            int max = -1;
            for (it; it<nums2.end(); it++) {
                if (*it > nums1[i]) {
                    max = *it;
                    break;
                }
            }
            res.push_back(max);
        }
        
        return res;
    }
};