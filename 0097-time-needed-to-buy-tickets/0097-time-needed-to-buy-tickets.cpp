class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        while (true) {
            for (auto i = 0; i < tickets.size() && tickets.at(k) != 0; i++) {
                if (tickets.at(i) <= 0)
                    continue;
                tickets[i]--;
                time++;
            }

            if (tickets.at(k) == 0)
                break;
        }

        return time;
    }
};