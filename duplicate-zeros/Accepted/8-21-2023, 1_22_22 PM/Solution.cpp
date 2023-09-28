// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>::iterator it = arr.begin();
        int cnt = 0;
        int orig_size = arr.size();
        while (cnt < orig_size) {
            if (*it == 0 && cnt < orig_size - 1) {
                arr.pop_back();
                arr.insert(it + 1, 1, 0);
                it += 1;
                cnt++;
            }
            it++;
            cnt++;
        }
        arr.resize(orig_size);
    }
};