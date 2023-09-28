// https://leetcode.com/problems/fair-candy-swap

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        if (aliceSizes.size() == 0 && bobSizes.size() == 0)
            return {0, 0};
        int sum_a = 0, sum_b = 0;
        unordered_set<int> sB;
        for (auto i : aliceSizes)
            sum_a += i;
        for (auto i : bobSizes) {
            sum_b += i;
            sB.insert(i);
        }
        
        int delta = (sum_b - sum_a) / 2;
        

        if (sum_a == sum_b)
            return {0, 0};
        
        for (auto i : aliceSizes) {
            if (sB.find(i + delta) != sB.end())
                return {i, i + delta};
        }
        return {0, 0};
    }
};