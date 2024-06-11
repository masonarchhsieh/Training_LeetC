class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        sort(arr1.begin(), arr1.end());
        for (int i=0; i<arr2.size(); i++) {
            int c = count(arr1.begin(), arr1.end(), arr2[i]);
            for (int j=0; j<c; j++)
                res.push_back(arr2[i]);
        }
        
        for (int i=0; i<arr1.size(); i++) {
            if (count(arr2.begin(), arr2.end(), arr1[i]) == 0)
                res.push_back(arr1[i]);
        }
        
        return res;
    }
};