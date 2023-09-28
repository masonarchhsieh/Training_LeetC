// https://leetcode.com/problems/sorting-the-sentence

bool Sort(const string &s1, const string &s2) {
    return s1[s1.length() - 1] < s2[s2.length() - 1];
}
class Solution {
public:
    string sortSentence(string s) {
        string res;
        vector<string> s_v;
        stringstream ss(s);

        while (ss) {
            string tmp;
            ss >> tmp;
            if (tmp != "")
                s_v.push_back(tmp);
        }
        sort(s_v.begin(), s_v.end(), Sort);
        for (auto i : s_v)
            res += i.substr(0, i.length() - 1) + " ";

        return res.substr(0, res.length() - 1);
    }
};