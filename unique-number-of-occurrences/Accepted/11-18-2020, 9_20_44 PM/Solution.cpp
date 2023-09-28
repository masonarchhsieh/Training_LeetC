// https://leetcode.com/problems/unique-number-of-occurrences

   bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
    {
           return a.second>b.second;
    }
class Solution {
public:   
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<pair<int, int>> occs;
        
        for (int i=0; i<arr.size(); i++) {
            
            bool check = true;
            for (int j=0; j<occs.size(); j++) {
                if (occs[j].first == arr[i]) {
                    check = false;
                    occs[j].second++;
                    break;
                }
            }
            if (check) {
                occs.push_back(make_pair(arr[i], 1));
            }
        }
        
        sort(occs.begin(), occs.end(), sortbysecdesc);
        for (int i=1; i<occs.size(); i++) {
            if (occs[i-1].second == occs[i].second)
                return false;
        }
    
        return true;
    }
};