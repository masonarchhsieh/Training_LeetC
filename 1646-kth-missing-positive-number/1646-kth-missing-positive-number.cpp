class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (auto i = 1; i < arr[arr.size() - 1]; i++) {
            if (find(arr.begin(), arr.end(), i) == arr.end())
                k--;
            if (k == 0)
                return i;
        }

        return arr[arr.size() - 1] + k;
    }
};