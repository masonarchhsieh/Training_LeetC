class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (auto i = 0; i < size(asteroids); i++) {
            if (asteroids[i] > 0 || st.empty()) {
                st.push(asteroids[i]);
                continue;
            }
            // asteroids[i] < 0
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
                st.pop();
            if (!st.empty() && st.top() == abs(asteroids[i]))
                st.pop();
            else {
                // asteroids[i] has the same dir as st.top()
                if (st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
            }
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};