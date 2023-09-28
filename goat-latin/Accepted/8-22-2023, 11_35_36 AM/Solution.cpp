// https://leetcode.com/problems/goat-latin

class Solution {
    char vows[5] = { 'a', 'e', 'i', 'o', 'u' };
public:
    string toGoatLatin(string sentence) {
        string res;
        int idx = 0;
        bool start_c_is_vow = false;
        stringstream ss(sentence);
        int cnt = 0;

        while (ss) {
            string tmp;
            ss >> tmp;
            cout << tmp << endl;

            if (find(vows, vows + 5, tolower(tmp[0])) < vows + 5) {
                // append "ma" to the end of the word
                tmp += "ma";
            }
            else if (tmp != "") {
                // remove the first letter and append it to the end, then add "ma"
                tmp = tmp.substr(1) + tmp.substr(0, 1) + "ma";
            }
            cnt++;
            if (tmp != "")
                for (auto i = 0; i < cnt; i++)
                    tmp += "a";
            if (ss)
                tmp += " ";

            res += tmp;
        }

        return res.substr(0, res.length() - 1);
    }
};