class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (auto i : arr)
            m[i]++;
        
        vector<int> occ;
        for (auto &i : m)
            occ.push_back(i.second);
        sort(occ.begin(), occ.end());

        int cnt = 0;
        for (auto i : occ) {
            if (k >= i) {
                k -= i;
                cnt++;
                continue;
            }
            break;
        }

        return occ.size() - cnt;
    }
};