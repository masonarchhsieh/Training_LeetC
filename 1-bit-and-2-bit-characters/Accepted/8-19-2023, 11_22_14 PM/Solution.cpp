// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits[bits.size() - 1] == 1)
            return false;
        for (auto i = 0; i < bits.size();) {
            if (bits[i] == 0) {
                i++;
                if (i == bits.size())
                    return true;
            }
            else
                i+=2;
        }

        return false;
    }
};