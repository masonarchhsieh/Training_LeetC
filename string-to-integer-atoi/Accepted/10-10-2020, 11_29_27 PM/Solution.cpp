// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int itr = 0;
        long int res = 0;

        bool firstD = false;
        bool symbol = false;
        while (itr < s.length())
        {
            if (!isspace(s[itr]) && !isdigit(s[itr]) && s[itr] != '-' && s[itr] != '+')
                return 0;
            
            if (isspace(s[itr]) && symbol)
                return 0;
            
            if (s[itr] == '+' || s[itr] == '-')
            {    
                if (!symbol)
                    symbol = true;
                else
                    return 0;

                if (s[itr] == '-')
                    sign = -1;
            
            }
            
            


            if (isdigit(s[itr]))
            {
                firstD = true;
                for (int i=itr; i<s.length(); i++)
                {
                    if (!isdigit(s[i]))
                        break;
                    
                    res = res * 10 + (s[i] - '0');
                    if (res * sign > INT_MAX)
                        return (int) INT_MAX;
                    if (res * sign < INT_MIN)
                        return (int) INT_MIN;
                }
                
                break;
            }
            itr++;
        }
        
        res = sign * res;
        
        if (res > INT_MAX)
            res = INT_MAX;
        if (res < INT_MIN)
            res = INT_MIN;
        
        return (int) res;
    }
};