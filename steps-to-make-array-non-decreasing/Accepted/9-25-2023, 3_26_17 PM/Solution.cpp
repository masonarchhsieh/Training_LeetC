// https://leetcode.com/problems/steps-to-make-array-non-decreasing

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size(), i, ans = 0, cnt = 0;
        stack<pair<int, int>> st;
        st.push({nums[n-1], 0});
        
        for (i = n - 2; i >= 0; i--) {
            cnt = 0;
            while (!st.empty() && nums[i] > st.top().first) {
                cnt = max(cnt + 1, st.top().second);
                st.pop();
            }
            ans = max(ans, cnt);
            st.push({nums[i], cnt});
        }
        return ans;
    }
};