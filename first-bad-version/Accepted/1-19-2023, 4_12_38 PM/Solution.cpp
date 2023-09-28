// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long low = 1, high = n;
        long mid, res = 1;
        
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (isBadVersion(mid))
            {
                res = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }
        
        return (int) res;
    }
};