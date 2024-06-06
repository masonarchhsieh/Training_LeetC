class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for (auto i : hand)
            m[i]++;
        
        for (auto it = m.begin(); it != m.end(); ) {
            if (it->second <= 0) {
                it++;
                continue; 
            }
            for (auto i = 0; i < groupSize; i++) {
                if (m[it->first + i] <= 0)
                    return false;
                m[it->first + i]--;
            }
        }
        return true;
    }
};