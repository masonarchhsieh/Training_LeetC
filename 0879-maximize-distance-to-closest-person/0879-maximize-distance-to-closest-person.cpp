class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = size(seats);
        vector<int> prefix(n, 0), suffix(n, 0);

        prefix[0] = seats.front() == 1? 0 : 1;
        suffix[n - 1] = seats.back() == 1? 0 : 1;

        for (auto i = 1; i < n; i++) {
            if (seats[i] == 1)
                prefix[i] = 0;
            else
                prefix[i] = prefix[i - 1] + 1;

            if (seats[n - 1 - i] == 1)
                suffix[n - 1 - i] = 0;
            else
                suffix[n - 1 - i] = suffix[n - 1 - i + 1] + 1;
        }

        prefix[0] = seats.front() == 1? 0 : INT_MAX;
        suffix[n - 1] = seats.back() == 1? 0 : INT_MAX;

        int seat = 0;
        for (auto i = 1; i < n; i++) {
            if (min(prefix[seat], suffix[seat]) < min(prefix[i], suffix[i])) {
                seat = i;
            }
        }
        
        return min(prefix[seat], suffix[seat]);
    }
};