// https://leetcode.com/problems/slowest-key

// Structure of the operator
// overloading for comparison
struct myComp {
    constexpr bool operator()(
        pair<char, int> const& a,
        pair<char, int> const& b)
        const noexcept
    {
        if (a.second == b.second)
            return a < b;
        return a.second <= b.second;
    }
};

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, myComp> pq;
        pq.push(make_pair(keysPressed[0], releaseTimes[0]));
        
        for (auto i = 1; i < releaseTimes.size(); i++) {
            pq.push(make_pair(keysPressed[i], releaseTimes[i] - releaseTimes[i - 1]));
        }

        pair<int, int> top = pq.top();
        return top.first;
    }
};