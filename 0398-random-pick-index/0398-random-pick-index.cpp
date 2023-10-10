class Solution {
    unordered_map<long long, vector<long long>> m;
public:
    Solution(vector<int>& nums) {
        for (auto i = 0; i < size(nums); i++)
            m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int range = m[target].size();
        int _pick = rand() % range;
        return m[target][_pick];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */