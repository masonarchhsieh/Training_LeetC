// https://leetcode.com/problems/maximum-swap

class Solution {
public:
    int maximumSwap(int num) {
        
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num%10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        bool swap = false;
        for (int i=0; i<digits.size(); i++) {
            int swap_itr = i;
            for (int j=i+1; j<digits.size(); j++) {
                if (digits[j] >= digits[swap_itr] && digits[j] != digits[i]) {
                    swap_itr = j;
                    swap = true;
                }
            }
            
            if (swap) {
                int t = digits[i];
                digits[i] = digits[swap_itr];
                digits[swap_itr] = t;
                break;
            }
        }
        
        reverse(digits.begin(), digits.end());

        int res = 0;
        while (!digits.empty()) {
            res = res * 10 + digits.at(digits.size()-1);
            digits.pop_back();
        }
        
        
        return res;
    }
};