class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);

        for (auto c : tasks)
            v[c - 'A']++;
        
        sort(v.begin(), v.end());
        int n_slots = v.back() - 1;
        int idel = n * n_slots;

        for (auto i = 0; i < v.size() - 1; i++) {
            idel -= min(n_slots, v[i]);
        }
        
        return idel < 0? tasks.size() : tasks.size() + idel;
    }
};