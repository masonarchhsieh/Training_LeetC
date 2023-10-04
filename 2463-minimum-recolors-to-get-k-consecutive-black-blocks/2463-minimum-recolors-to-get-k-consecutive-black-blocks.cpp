class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // k is the window length
        int res = k;
        size_t i = 0, len = blocks.length();
        int num_of_white_blocks_in_window = 0;

        while (i < len) {
            if (blocks[i] == 'W')
                num_of_white_blocks_in_window++;
            if (i >= k && blocks[i - k] == 'W')
                num_of_white_blocks_in_window--;
            
            res = (i >= k - 1)? min(res, num_of_white_blocks_in_window) : res;
            i++;
        }
        return res;
    }
};