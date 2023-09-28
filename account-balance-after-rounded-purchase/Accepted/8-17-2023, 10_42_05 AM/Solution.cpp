// https://leetcode.com/problems/account-balance-after-rounded-purchase

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int roundup = purchaseAmount;
        int rounddown = purchaseAmount;
        
        while (roundup % 10 != 0 && rounddown % 10 != 0) {
            roundup++;
            rounddown--;
        }

        if (roundup % 10 == 0) {
            return 100 - roundup;
        }

        return 100 - rounddown;
    }
};