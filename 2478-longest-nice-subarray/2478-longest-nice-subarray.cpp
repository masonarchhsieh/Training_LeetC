class Solution {
    unordered_map<int, int> m;
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0, sub_array_len = 0;
        for (auto l = 0, r = 0; r < nums.size(); r++) {
            if (!isNiceSubArray(nums[r])) {
                res = max(res, sub_array_len);
                while (true) {
                    clearBits(nums[l++]);
                    sub_array_len--;
                    if (isNiceSubArray(nums[r]))
                        break;
                }
            }
            updateBits(nums[r]);
            sub_array_len++;
        }
        res = max(res, sub_array_len);

        return res;
    }

    bool isNiceSubArray(int n) {
        int idx = 0;
        while (n > 0) {
            if (n & 0x1 && m[idx] > 0)
                return false;
            n >>= 1;
            idx++;
        }
        return true;
    }

    void updateBits(int n) {
        int idx = 0;
        while (n > 0) {
            if (n & 0x1)
                m[idx]++;
            n >>= 1;
            idx++;
        }
    }

    void clearBits(int n) {
        int idx = 0;
        while (n > 0) {
            if (n & 0x1)
                m[idx]--;
            n >>= 1;
            idx++;
        }
    }
};