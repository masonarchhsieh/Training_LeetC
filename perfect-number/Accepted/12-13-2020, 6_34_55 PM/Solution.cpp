// https://leetcode.com/problems/perfect-number

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sqrt_num = (int) sqrt(num);
        vector<int> divisors;
        for (int i=1; i<=sqrt_num; i++) {
            if (num % i == 0) {
                int alt = num / i;
                divisors.push_back(i);
                divisors.push_back(alt);
            }
        }
        sort(divisors.begin(), divisors.end());
        vector<int>::iterator it;
        it = unique(divisors.begin(), divisors.end());
        divisors.resize(distance(divisors.begin(), it));
        
        int sum = 0;
        for (int i=0; i<divisors.size(); i++) {
            sum += divisors[i];
        }
        
        return (sum == 2 * num)? true : false;;
    }
};