// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() < 10)
            return res;
        unordered_set<string> sequence;
        string temp;
        for (auto i = 0; i < s.length(); i++) {
            temp += s[i];
            if (i >= 10) {
                temp.erase(temp.begin(), temp.begin() + 1);
            }
            if (i >= 9) {
                cout << temp << endl;
                if (sequence.find(temp) != sequence.end()) {
                    res.push_back(temp);
                } else {
                    sequence.insert(temp);
                }
            }
        }

        vector<string>::iterator it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));
        return res;
    }   
};