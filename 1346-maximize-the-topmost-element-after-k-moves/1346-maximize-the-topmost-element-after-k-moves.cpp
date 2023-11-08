class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (size(nums) == 1 && k % 2 == 1)
            return -1;
        if (k < 2)
            return nums[k];

        if (k > size(nums)) {
            priority_queue<int> pq_k(begin(nums), end(nums));
            return pq_k.top();
        }
        // k <= size(nums)
        priority_queue<int> pq(begin(nums), begin(nums) + k - 1);
        // return pq.top();
        return max(pq.top(), nums[k]);
    }
};