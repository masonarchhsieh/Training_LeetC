class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<int> pq;
        vector<int> res;
        auto index = 0, left = 0;

        while (index < size(nums)) {
            m[nums[index]]++;
            pq.push(nums[index]);
            if (index - left + 1 < k)
                index++;
            else if (index - left + 1 == k) {
                res.push_back(pq.top());
                m[nums[left]]--;
                while (!pq.empty() && m[pq.top()] == 0)
                    pq.pop();
                
                index++;
                left++;
            }
        }
        
        return res;
    }
};