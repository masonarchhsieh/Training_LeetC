// https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        
        int min = INT_MAX;
        for (int i=1; i<arr.size(); i++) {
            if (arr[i] - arr[i-1] <= min) {
                if (arr[i] - arr[i-1] < min) {
                    while (!res.empty())
                        res.pop_back();
                    min = arr[i] - arr[i-1];
                }
                vector<int> t;
                t.push_back(arr[i-1]);
                t.push_back(arr[i]);
                res.push_back(t);
            }
        }
        
        
        return res;
    }
};