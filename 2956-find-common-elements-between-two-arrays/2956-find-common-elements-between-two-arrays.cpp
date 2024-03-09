class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for (auto i : nums1)
            m1[i]++;
        for (auto i : nums2)
            m2[i]++;
        
        vector<int> res = {0, 0};
        for (auto i : m1) {
            if (m2.find(i.first) == m2.end())
                continue;
            res[0] += i.second;
            res[1] += m2[i.first];
        }

        return res;

    }
};