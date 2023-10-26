class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q_r, q_d;
        int n = size(senate);
        for (auto i = 0; i < n; i++)
            if (senate[i] == 'R')
                q_r.push(i);
            else
                q_d.push(i);

        
        while (!q_r.empty() && !q_d.empty()) {
            if (q_r.front() < q_d.front())
                q_r.push(n++);
            else
                q_d.push(n++);
            q_r.pop();
            q_d.pop();

        }
        
        return q_r.empty()? "Dire" : "Radiant";
    }
};