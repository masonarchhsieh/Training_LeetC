class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (auto e2 : nums2)
            for (auto e1 : nums1)
                if (e2 == e1)
                    if (find(res.begin(), res.end(), e1) == res.end())
                        res.push_back(e1);

        return res;
    }
};