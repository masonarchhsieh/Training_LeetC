// https://leetcode.com/problems/furthest-point-from-origin

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0, countR = 0, both = 0;
        for (size_t i = 0; i < moves.length(); i++) {
            if (moves[i] == 'L')
                countL++;
            else if (moves[i] == 'R')
                countR++;
            else
                both++;    
        }

        return abs(countR - countL) + both;
    }
};