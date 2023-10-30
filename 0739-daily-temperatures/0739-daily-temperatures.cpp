class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(size(temperatures), 0);
        stack<int> st;
        
        for (int i = 0; i < (int) size(temperatures); i++) {
            while (!st.empty() && temperatures.at(st.top()) < temperatures.at(i)) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};