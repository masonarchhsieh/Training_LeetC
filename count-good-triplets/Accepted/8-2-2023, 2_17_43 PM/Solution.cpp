// https://leetcode.com/problems/count-good-triplets

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;

        for (auto i = 0; i < arr.size() - 2; i++) {
            for (auto j = i + 1; j < arr.size() - 1; j++) {
                for (auto k = j + 1; k < arr.size(); k++) {
                    if (abs(arr[i] - arr[j]) <= a 
                    && abs(arr[j] - arr[k]) <= b
                    && abs(arr[i] - arr[k]) <= c  
                    ) {
                        count++;
                    }
                }
            }
        }


        return count;
    }
};