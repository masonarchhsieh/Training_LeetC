class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long mass_bk = mass;
        sort(asteroids.begin(), asteroids.end());
        for (auto i = 0; i < asteroids.size(); i++) {
            if (mass_bk < asteroids[i])
                return false;
            mass_bk += asteroids[i];
            
        }
        return true;
    }
};