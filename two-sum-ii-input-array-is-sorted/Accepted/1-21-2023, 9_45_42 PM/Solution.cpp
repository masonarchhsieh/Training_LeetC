// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res { -1, -1 };

       int i = 0, j = numbers.size() - 1;

       while (i <= j) {
           if (numbers[i] + numbers[j] == target) {
               res[0] = i + 1;
               res[1] = j + 1;
               goto end;
           }
           else if (numbers[i] + numbers[j] > target) {
               j -= 1;
           }
           else {
               i += 1;
           }
       }

end:
        return res;
    }
};