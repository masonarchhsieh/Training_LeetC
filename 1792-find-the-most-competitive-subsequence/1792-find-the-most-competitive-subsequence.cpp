class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> monotonic_stack;

        for (auto i = 0; i < size(nums); i++) {
            while (!monotonic_stack.empty() && monotonic_stack.top() > nums[i] && 
                (k - size(monotonic_stack) <= size(nums) - i - 1)) {
                monotonic_stack.pop();
            }
            if (monotonic_stack.size() < k)
                monotonic_stack.push(nums.at(i));
        }

        vector<int> res;
        while (!monotonic_stack.empty()) {
            res.push_back(monotonic_stack.top());
            monotonic_stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};