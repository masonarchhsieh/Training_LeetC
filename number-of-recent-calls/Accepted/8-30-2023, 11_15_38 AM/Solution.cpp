// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter {
    vector<int> calls;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        calls.push_back(t);
        
        int lastIdx = -1;
        for (auto i = 0; i < calls.size(); i++) {
            if (calls[i] < t - 3000) {
                lastIdx = i;
                continue;
            }
            break;
        }
        cout << lastIdx << endl;
        if (lastIdx > -1) {
            calls = vector(calls.begin() + lastIdx + 1, calls.end());
        }

        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */