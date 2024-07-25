class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : nums)
            pq.push(i);
        
        int i = 0;
        while (!pq.empty()) {
            nums[i++] = pq.top();
            pq.pop();
        }

        return nums;
    }
};