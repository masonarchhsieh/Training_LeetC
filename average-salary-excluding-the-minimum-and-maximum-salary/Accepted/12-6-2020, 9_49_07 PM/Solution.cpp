// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int sum = 0;
        for (int i=1; i<salary.size()-1; i++) {
            sum += salary[i];
        }
        
        return (double) ((double) sum / (double) (salary.size()-2));
    }
};