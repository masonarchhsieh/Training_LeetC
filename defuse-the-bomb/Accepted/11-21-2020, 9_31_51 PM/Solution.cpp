// https://leetcode.com/problems/defuse-the-bomb

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res;
        res.assign(code.size(), 0);
        
        for (int i=0; i<res.size(); i++) {
            int temp = 0, itr = 0;
            if (k >= 0) {
                while (itr++ < k) {
                    if (i + itr >= code.size()) {
                        temp += code[i+itr-code.size()];
                    } else {
                        temp += code[i+itr];
                    }
                }
            }
            else {
               while (itr-- > k) {
                    if (i + itr < 0) {
                        temp += code[code.size() + i + itr];
                    } else {
                        temp += code[i+itr];
                    }
                }
            }
            
            res[i] = temp;
        }
        
        
        return res;
    }
};