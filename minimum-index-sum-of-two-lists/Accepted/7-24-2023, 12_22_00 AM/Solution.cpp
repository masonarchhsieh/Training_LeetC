// https://leetcode.com/problems/minimum-index-sum-of-two-lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int list1_itx = list1.size(), list2_itx = list2.size();
        vector<string> res;

        for (auto i = 0; i < list1.size(); i++) {
            for (auto j = 0; j < list2.size(); j++) {
                if (list1[i] == list2[j]) {
                    if (list1_itx + list2_itx > i + j) {
                        list1_itx = i;
                        list2_itx = j;
                        res.clear();
                        res.push_back(list1[i]);
                    }
                    else if (list1_itx + list2_itx == i + j) {
                        res.push_back(list1[i]);
                    }
                }
            }
        }

        return res;
    }
};