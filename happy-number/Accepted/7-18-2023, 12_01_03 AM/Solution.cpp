// https://leetcode.com/problems/happy-number

class Solution {
    vector<int> list;

public:
    bool isHappy(int n) {
        if (find(list.begin(), list.end(), n) != list.end())
            return false;
        list.push_back(n);
        if (n == 1)
            return true;
        
        long long tmp = 0;
        while (n) {
            tmp = tmp + (n % 10) * (n % 10);
            n /= 10;
        }
        return isHappy(tmp);
    }
};