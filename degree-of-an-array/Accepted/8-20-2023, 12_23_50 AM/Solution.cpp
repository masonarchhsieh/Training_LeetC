// https://leetcode.com/problems/degree-of-an-array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> tmp;
        for (auto i = 0; i < nums.size(); i++) {
            tmp[nums[i]]++;  
        }
        
        int max_num = nums[0], max_cnt = tmp[nums[0]];
        for (auto i : tmp) {
            if (i.second > max_cnt) {
                max_cnt = i.second;
                max_num = i.first;
            }
        }
        cout << "max_num " << max_num << "; max_cnt: " << max_cnt << endl;
        int res = INT_MAX;
        for (auto i : tmp) {
            if (i.second == max_cnt) {
                int head_idx = -1, tail_idx = -1;
                for (auto j = 0; j < nums.size() && (head_idx < 0 || tail_idx < 0); j++) {
                    if (head_idx < 0 && nums[j] == i.first)
                        head_idx = j;
                    if (tail_idx < 0 && nums[nums.size() - 1 - j] == i.first)
                        tail_idx = nums.size() - 1 - j;
                }
                res = min(res, tail_idx - head_idx);
            }
        }

        return res + 1;
    }
};