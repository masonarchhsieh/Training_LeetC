class Solution {
    vector<int> v;
public:
    Solution(vector<int>& w) {
        v = w;
        for (auto i = 1; i < size(v); i++) {
            v[i] = v[i] + v[i - 1];
        }
    }
    
    int pickIndex() {
        int total = v.back();
        int index = 1 + rand() % total;
        
        return (int) (lower_bound(v.begin(), v.end(), index) - v.begin());
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */