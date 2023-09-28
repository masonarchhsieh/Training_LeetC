// https://leetcode.com/problems/self-dividing-numbers

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        
        for (auto i=left; i<=right; i++) {
            int num_itr = i;
            int div = num_itr % 10;
            bool check = true;
            while (num_itr > 0) {
                if (div == 0 || i % div != 0) {
                    check = false;
                    break;
                }
                
                num_itr = num_itr / 10;
                div = num_itr % 10;
            }
            if (check)
                res.push_back(i);
        }
        
        return res;
    }
};