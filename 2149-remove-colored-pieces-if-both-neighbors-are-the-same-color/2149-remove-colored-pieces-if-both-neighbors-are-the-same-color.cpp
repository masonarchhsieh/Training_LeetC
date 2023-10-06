class Solution {
public:
    bool winnerOfGame(string colors) {
        bool aliceMove = true;
        int num_A = 0, num_B = 0;
        
        for (size_t start = 0, end = 0; end < size(colors); ) {
            start = end;
            while (end < size(colors)) {
                if (colors[end] != colors[start]) {
                    if (end - start >= 2) {
                        if (colors[start] == 'A')
                            num_A += end - start - 2;
                        else
                            num_B += end - start - 2;
                    }
                    break;
                }
                if (end == size(colors) - 1 && end - start >= 2) {
                    if (colors[start] == 'A')
                        num_A += end - start - 1;
                    else
                        num_B += end - start - 1;
                }
                end++;
            }
        }
        return num_A > num_B;
    }
};