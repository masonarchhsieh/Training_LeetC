// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long high = n;
        long mid;
        long low = 0;
        if (guess(n)==0) return n;
        while (low < high)
        {
            mid = (low + high)/2;
            if (guess(mid)==0) break;
            else if (guess(mid)==-1)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return mid;
    }
};