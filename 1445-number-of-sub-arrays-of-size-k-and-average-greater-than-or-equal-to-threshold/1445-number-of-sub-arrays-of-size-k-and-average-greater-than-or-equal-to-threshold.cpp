class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int _threshold = k * threshold;
        int current_sum = accumulate(arr.begin(), arr.begin() + k, 0);
        int res = current_sum >= _threshold;

        for (auto i = 1; i <= arr.size() - k && i + k <= arr.size(); i++) {
            current_sum = current_sum - arr[i - 1] + arr[i + k - 1];
            res += (current_sum >= _threshold);
        }
        

        return res;
    }
};