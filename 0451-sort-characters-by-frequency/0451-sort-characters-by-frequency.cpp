struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (const char c : s)
            m[c]++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, myComp> pq;
        for (auto i : m)
            pq.push(make_pair(i.first, i.second));

        string res;
        while (!pq.empty()) {
            res = res + std::string(pq.top().second, pq.top().first);
            pq.pop();
        }
        return res;
    }
};