class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beams = 0;
        
        int low = 0;
        int l = 0;
        for (l = 0; l < size(bank); l++) {
            low = count(begin(bank.at(l)), end(bank.at(l)), '1');
            if (low != 0)
                break;
        }
        
        for (; l < size(bank);) {
            if (low == 0) {
                l++;
                continue;
            }
            
            int r = l + 1;
            int high = 0;
            for (r = l + 1; r < size(bank); r++) {
                high = count(begin(bank.at(r)), end(bank.at(r)), '1');
                if (high != 0)
                    break;
            }
            beams += low * high;
            l = r;
            low = high;
        }
        
        return beams;
    }
};