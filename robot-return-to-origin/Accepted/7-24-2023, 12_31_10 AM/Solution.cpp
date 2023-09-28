// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        int hori_coord = 0, vert_coord = 0;

        for (auto i = 0; i < moves.length(); i++) {
            switch (moves[i]) {
                case 'U':
                    vert_coord++;
                    break;
                case 'D':
                    vert_coord--;
                    break;
                case 'R':
                    hori_coord++;
                    break;
                case 'L':
                    hori_coord--;
                    break;
                default:
                    break;
            }
        }

        return (hori_coord == 0 && vert_coord == 0);
    }
};