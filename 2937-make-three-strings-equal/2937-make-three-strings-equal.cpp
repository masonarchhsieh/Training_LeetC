class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if (s1[0] != s2[0] || s2[0] != s3[0] || s3[0] != s1[0])
            return -1;
        
        int size_m = min({size(s1), size(s2), size(s3)});
        int i = 0;
        for (i = 0; i < size_m; i++)
            if (s1[i] != s2[i] || s2[i] != s3[i])
                return size(s1) + size(s2) + size(s3) - 3 * i;

        return size(s1) + size(s2) + size(s3) - 3 * i;
    }
};