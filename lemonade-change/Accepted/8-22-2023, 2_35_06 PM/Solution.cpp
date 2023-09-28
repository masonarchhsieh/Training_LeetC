// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> changes { 0, 0 };

        for (auto i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                changes[0]++;
            else if (bills[i] == 10) {
                if (changes[0] <= 0) 
                    return false;
                changes[0]--;
                changes[1]++;
            } else if (bills[i] == 20) {
                if (changes[1] > 0 && changes[0] > 0) {
                    changes[1]--;
                    changes[0]--;
                } else if (changes[0] >= 3)
                    changes[0] -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};