// https://leetcode.com/problems/shortest-distance-to-a-character

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        res.assign(S.length(), 0);

        for (int i=0; i<S.length(); i++) {
            int itr = 0;
            if (S[i] == C)
                res[i] = 0;
            else {
                int prev = i, next = i;
                while (true) {
                    if (prev >= 0 && S[prev] == C) {
                        res[i] = abs(prev - i); break;
                    }
                    if (next < S.length() && S[next] == C){
                        res[i] = abs(next - i); break;
                    }
                    prev--;
                    next++;
                }
            }
        }
        
        return res;
    }
};