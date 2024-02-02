class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string seq = "0123456789";
        set<int> res;
        
        for (auto i = 0; i < seq.size(); i++) {
            string t;
            for (auto j = i; j < seq.size(); j++) {
                t += seq[j];
                int num = stoi(t);
                if (low <= num && num <= high)
                    res.insert(num);
            }
        }
        
        return vector<int>(res.begin(), res.end());
    }
};