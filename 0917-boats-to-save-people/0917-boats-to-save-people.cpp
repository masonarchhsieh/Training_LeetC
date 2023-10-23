class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int n = 0;
        int l = 0, r = size(people) - 1;

        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            }
            else
                r--;
            n++;
        }
        return n;
    }
};