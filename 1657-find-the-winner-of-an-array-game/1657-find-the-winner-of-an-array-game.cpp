class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k == 1)
            return max(arr[0], arr[1]);
        if (k >= size(arr))
            return *max_element(begin(arr), end(arr));
        int cnt = 0;
        int _val = arr.front();

        for (auto i = 1; i < size(arr); i++) {
            if (arr.at(i) > _val) {
                _val = arr.at(i);
                cnt = 1;
                continue;
            }
            cnt++;
            if (cnt == k)
                break;
        }

        return _val;
    }
};