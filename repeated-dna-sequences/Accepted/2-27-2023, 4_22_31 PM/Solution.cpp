// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() < 10)
            return res;
        unordered_map<string, int> sequence;
        string temp;
        for (auto i = 0; i < s.length(); i++) {
            temp += s[i];
            if (i >= 10) {
                temp.erase(temp.begin(), temp.begin() + 1);
            }
            if (i >= 9) {
                cout << temp << endl;
                if (sequence.find(temp) != sequence.end()) {
                    sequence[temp]++;
                } else {
                    sequence[temp] = 0;
                }
            }
        }

        for (auto a : sequence) {
            if (a.second > 0)
                res.push_back(a.first);
        }
        return res;
    }   
};