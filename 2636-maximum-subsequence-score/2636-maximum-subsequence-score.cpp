class Solution {
    static bool compare(vector<int> &v1, vector<int> &v2) {
        if (v1.front() == v2.front())
            return v1.back() < v2.back();
        return v1.front() < v2.front();
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        for (auto i = 0; i < size(nums1); i++) 
            v.push_back({nums2.at(i), nums1.at(i)});
        
        priority_queue<int, vector<int>, greater<int>> pq;  //ordered from small -> large
        sort(begin(v), end(v), compare);
        long long res = 0, sum = 0;
        int j = 0;
        for (int i = size(nums1) - 1; i >= 0; i--) {
            sum += v.at(i).back();
            pq.push(v.at(i).back());
            if (i >= size(nums1) - k + 1)
                continue;
            if (size(pq) > k) {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, (long long) sum * v.at(i).front());
        }
        return res;
    }
};