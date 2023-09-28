// https://leetcode.com/problems/final-value-of-variable-after-performing-operations

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for (auto i : operations) {
            if (i == "++X" || i == "X++")
                val++;
            else if (i == "--X" || i == "X--")
                val--;   
        }
        return val;
    }
};