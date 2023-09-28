// https://leetcode.com/problems/count-symmetric-integers

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        unordered_set<int> ints;

        for (auto i = low; i <= high; i++) {
            vector<int> t;
            int tmp = i;
            while (tmp > 0) {
                t.push_back(tmp % 10);
                tmp /= 10;
            }
            if (t.size() % 2 != 0)
                continue;
            if (accumulate(t.begin(), t.begin() + t.size() / 2, 0) ==
                accumulate(t.begin() + t.size() / 2, t.end(), 0)) {
                    ints.insert(i);
                    cnt++;
            }
        } 

        return cnt;
    }
};