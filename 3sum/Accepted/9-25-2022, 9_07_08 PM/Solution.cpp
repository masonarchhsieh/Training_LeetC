// https://leetcode.com/problems/3sum

bool isUnique(vector<int> f, vector<int> s) {
    for (int i=0;i<f.size();i++) {
        if (f[i] != s[i]) {
            return false;
        }
    }
    return true;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> r;
        
        sort(nums.begin(), nums.end());
        
        auto curr = nums.begin();
        
        while (curr < nums.end()) {
            auto low = curr + 1;    
            auto high = nums.end() - 1;
            auto required = -*curr;
            
            while (low < high) {
                auto sum = *low + *high;
                
                if (sum == required) {
                    r.push_back({*curr, *low, *high});
                    
                    auto prev = *low;
                    while (low < high && *low == prev) low++;
                    high--;
                } else if (sum < required) {
                    low++;
                } else {
                    high--;
                }
            }
            
            auto prev = *curr;
            while (curr < nums.end() && *curr == prev) ++curr;
        }
        
        return r;
    }
};