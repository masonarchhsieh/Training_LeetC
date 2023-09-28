// https://leetcode.com/problems/sort-array-by-increasing-frequency

bool sortArr(const pair<int, int> f, const pair<int, int> s) {
    if (f.second > s.second)
        return true;
    else if (f.second == s.second) {
        if (f.first < s.first)
            return true;
    }
    
    return false;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> num_pairs;
        
        for (int i=0; i<nums.size(); i++) {
            bool check = true;
            for (int j=0; j<num_pairs.size(); j++) {
                if (num_pairs[j].first == nums[i]) {
                    check = false;
                    num_pairs[j].second++;
                    break;
                }
            }
            if (check) {
                pair p = make_pair(nums[i], 1);
                num_pairs.push_back(p);
            }
        }
        
        sort(num_pairs.begin(), num_pairs.end(), sortArr);
        
        vector<int> res;
        for (int i=0; i<num_pairs.size(); i++) {
            for (int j=0; j<num_pairs[i].second; j++) {
                res.push_back(num_pairs[i].first);
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};