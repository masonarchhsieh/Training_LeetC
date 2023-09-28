// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> changes;

        for (auto i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                changes[5]++;
            else if (bills[i] == 10) {
                if (changes[5] <= 0) 
                    return false;
                changes[5]--;
                changes[10]++;
            } else if (bills[i] == 20) {
                if (changes[10] > 0 && changes[5] > 0) {
                    changes[10]--;
                    changes[5]--;
                } else if (changes[5] >= 3)
                    changes[5] -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};