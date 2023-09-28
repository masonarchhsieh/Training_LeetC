// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> ans0, ans1;
        for (auto i : set1)
            if (find(set2.begin(), set2.end(), i) == set2.end())   
                ans0.push_back(i);
        for (auto i : set2)
            if (find(set1.begin(), set1.end(), i) == set1.end())   
                ans1.push_back(i);
    

        return { ans0, ans1 };
    }
};