class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;
        stringstream ss(sentence);
        string tmp;
        ss >> tmp;
        while (ss) {
            bool found = false;
            for (auto i : dictionary) {
                if (tmp.substr(0, i.length()) == i) {
                    found = true;
                    tmp = i;
                }
            }

            res += tmp;
            ss >> tmp;
            if (ss)
                res += " ";
        }


        return res;
    }
};