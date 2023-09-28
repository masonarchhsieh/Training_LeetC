// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> pp(26, 0);
        vector<int> ss(26, 0);
        for(int i=0; i<m; i++){
            pp[p[i]-'a']++;
        }
        int j=0;
        vector<int> v;
        for(int i=0; i<n; i++){
            ss[s[i]-'a']++;
            if(i-j+1 == m){
                bool fl = true;
                for(int k=0; k<26; k++){
                    if(ss[k] != pp[k])
                        fl = false;
                }
                if(fl){
                    v.push_back(j);
                }
                ss[s[j]-'a']--;
                j++;
            }
        }
        return v;
    }
};