class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int boats = 0;

        int l = 0, r = size(people) - 1;
        while (l <= r) {
            boats++;
            if (people.at(l) + people.at(r) <= limit) {
                l++;
                r--;
                continue;
            }
            r--;
        }

        return boats;
    }
};