// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0, cnt = 0, part_sum = 0;
        for (auto i : arr)
            sum += i;
        if (sum % 3 != 0)
            return false;
        part_sum = sum / 3;
        sum = 0;
        for (auto i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == part_sum) {
                cnt++;
                sum = 0;
            }
        }

        return (cnt >= 3);
    }
};