// https://leetcode.com/problems/categorize-box-according-to-criteria

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky, heavy;

        bulky = (length >= 10000) || (width >= 10000) || (height >= 10000) || 
        ((long long) ((long long)length * (long long)width * (long long)height) >= 1000000000);
        heavy = (mass >= 100);
        if (bulky & heavy)
            return "Both";
        if (bulky)
            return "Bulky";
        if (heavy)
            return "Heavy";
        return "Neither";
    }
};