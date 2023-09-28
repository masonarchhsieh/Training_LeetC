// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second == b.second)
        return (a.first < b.first);
    return (a.second < b.second);
}

class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> copyvector(arr.size());
        copy(arr.begin(), arr.end(), copyvector.begin());
        
        vector<pair<int,int>> row;
        for (int i=0; i<copyvector.size(); i++) {
            row.push_back(make_pair(arr[i], 0));
        }
        
        
        for (int i=0; i<row.size(); i++) {
            for (int j=0; j<16; j++) {
                if ((copyvector[i] & 0x01) == 0x01) {
                    row[i].second++;
                }
                copyvector[i] = copyvector[i] >> 1;
            }
        }
        
        sort(row.begin(), row.end(), sortbysec);
        
        vector<int> res;
        for (int i=0; i<row.size(); i++) {
            res.push_back(row[i].first);
        }
        
        
        return res;
    }
    

};