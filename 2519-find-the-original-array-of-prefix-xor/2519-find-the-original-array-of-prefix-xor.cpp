class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(size(pref), 0);
        arr[0] = pref.front();
        for (auto i = 1; i < size(pref); i++)
            arr[i] = pref[i] ^ pref[i - 1];
        return arr;
    }
};