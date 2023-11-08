class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x_dist = abs(fx - sx);
        int y_dist = abs(fy - sy);
        if (x_dist > t || y_dist > t)
            return false;
        if (x_dist == 0 && y_dist == 0 && t == 1)
            return false;
        return true;
    }
};