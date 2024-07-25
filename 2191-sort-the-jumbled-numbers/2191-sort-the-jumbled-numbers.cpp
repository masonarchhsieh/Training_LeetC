class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> v;
        unordered_map<int, int> m;
        bool same = false;
        
        for (auto i = 0; i < nums.size(); i++) {
            int num = 0, dec = 1;
            int n = nums.at(i);
            while (n > 0) {
                num = dec * (mapping.at(n % 10)) + num;
                n /= 10;
                dec *= 10;
            }
            v.push_back(num);
            same |= (m[num]++ >= 1);
        }
        
        if (!same) {
            sort(begin(v), end(v));
            return v;
        }


        vector<int> v1, v2;
        for (auto i = 0; i < v.size(); i++) {
            if (m[v[i]] == 1) {
                v2.push_back(nums[i]);
                continue;
            }
            v1.push_back(nums[i]);
        }
        sort(begin(v2), end(v2));
        v1.insert(end(v1), begin(v2), end(v2));

        return v1;
    }
};