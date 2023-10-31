class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr(size(encoded) + 1, 0);
        arr[0] = first;

        for (auto i = 1; i <= size(encoded); i++) {
            arr[i] = encoded[i - 1] ^ arr[i - 1];
        }
        return arr;
    }
};