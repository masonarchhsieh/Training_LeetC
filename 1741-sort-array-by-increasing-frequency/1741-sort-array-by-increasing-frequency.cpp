bool cmp(const pair<int, int> &T1, const pair<int, int> &T2) {
    if (T1.second == T2.second)
        return T1.first > T2.first;
    return T1.second < T2.second;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        if (nums.size() == 1)
            return nums;
        
        vector<int> res;
        vector<pair<int, int>> nums_list;
        
        sort(nums.begin(), nums.end());
        int cnt = 1;
        for (auto i = 1; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                if (nums[i] != nums[i - 1]) {
                    nums_list.push_back(make_pair(nums[i - 1], cnt));
                    nums_list.push_back(make_pair(nums[i], 1));
                }
                else
                    nums_list.push_back(make_pair(nums[i], cnt + 1));
                break;
            }
            else if (nums[i] != nums[i - 1]) {
                nums_list.push_back(make_pair(nums[i - 1], cnt));
                cnt = 1;
            } else
                cnt++;
        }
        sort(nums_list.begin(), nums_list.end(), cmp);
        for (auto i : nums_list)
            for (auto j = 0; j < i.second; j++) {
                res.push_back(i.first);
            }  

        return res;
    }
};