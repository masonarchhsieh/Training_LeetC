// https://leetcode.com/problems/separate-the-digits-in-an-array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (auto i : nums) {
            vector<int> t;
            while (i > 0) {
                t.push_back(i % 10);
                i /= 10;
            }
            reverse(t.begin(), t.end());
            res.insert(res.end(), t.begin(), t.end());
        }

        return res;
    }
};