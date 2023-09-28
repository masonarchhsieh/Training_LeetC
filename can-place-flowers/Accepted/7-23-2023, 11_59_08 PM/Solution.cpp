// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int itr = 0;

        while (itr < flowerbed.size() && n > 0) {
            if (flowerbed[itr] == 1) {
                itr += 2;
                continue;
            }
            // if flowerbed[i] == 0
            if (itr-1 >= 0 && flowerbed[itr-1] == 1) {
                itr += 2;
                continue;
            }
            // if flowerbed[i+1] == 0
            if (itr+1 < flowerbed.size() && flowerbed[itr+1] == 1) {
                itr = itr + 1 + 2;
                continue;
            }
            
            flowerbed[itr] = 1;
            n--;
            itr += 2;
        }

        return n == 0;
    }
};