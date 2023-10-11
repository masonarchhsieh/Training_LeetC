struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        unordered_map<int, int> m;
        for (auto i : nums)
            m[i]++;
        
        for (auto i : m) {
            pq.push(make_pair(i.first, i.second));
        }
        
        vector<int> res;
        for (auto i = 0; i < k && !pq.empty(); i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};