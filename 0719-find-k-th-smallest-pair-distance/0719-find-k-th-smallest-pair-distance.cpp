class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        auto start = 0, end = nums.back() - nums.front();

        while (start <= end) {
            auto mid = start + (end - start) / 2;

            int count = 0, l = 0, r = 0;
            while (r < size(nums)) {
                while (nums[r] - nums[l] > mid && l < size(nums))
                    l++;
                
                count += (r - l);
                r++;
            }

            if (count >= k)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }
};